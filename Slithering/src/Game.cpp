#include "stdafx.h"
#include <src/Game.h>
#include <src/singletons/RegistrySingleton.h>

app::Game::Game()
	: m_gameLoop(true)
	, m_registry(app::sin::Registry::get())
	, m_keyHandler()
	, m_mouseHandler()
	, m_updateSystems({
		  UpdateSystem(std::in_place_type<sys::DebugSystem>)
		, UpdateSystem(std::in_place_type<sys::InputSystem>, m_keyHandler, m_mouseHandler)
		, UpdateSystem(std::in_place_type<sys::CommandSystem>)
		, UpdateSystem(std::in_place_type<sys::SegmentSystem>)
		, UpdateSystem(std::in_place_type<sys::MotionSystem>)
		, UpdateSystem(std::in_place_type<sys::FoodSystem>)
		, UpdateSystem(std::in_place_type<sys::CollisionTrackingSystem>)
		, UpdateSystem(std::in_place_type<sys::CameraTrackingSystem>)
		, UpdateSystem(std::in_place_type<sys::NeuralNetworkTrainingSystem>, m_gameLoop)
		, UpdateSystem(std::in_place_type<sys::NeuralNetworkSystem>)
		, UpdateSystem(std::in_place_type<sys::FsmSystem>)
		, UpdateSystem(std::in_place_type<sys::WrapAroundWorldSystem>)
		, UpdateSystem(std::in_place_type<sys::DestroySystem>)
	})
	, m_renderSystems{
		RenderSystem(std::in_place_type<sys::RenderSystem>, m_gameLoop)
	}
	, m_gameFactory()
{
}

app::Game::~Game()
{
}

bool app::Game::init()
{
	return this->createEntities() && this->initSystems();
}

void app::Game::deinit()
{
	for (UpdateSystem& updateSystem : m_updateSystems)
		std::visit(util::overload{
			  [this](sys::NeuralNetworkTrainingSystem& sys) { sys.deinit(); }
			, [](auto const& sys) constexpr {}
		}, updateSystem);
}

bool app::Game::initSystems()
{
	try
	{
		for (UpdateSystem & updateSystem : m_updateSystems)
			std::visit([](auto & sys) { sys.init(); }, updateSystem);
		for (RenderSystem & renderSystem : m_renderSystems)
			std::visit([](auto & sys) { sys.init(); }, renderSystem);
		return true;
	}
	catch (std::exception const & e)
	{
		app::cout::wrl({ "Error: ", e.what() });
		return false;
	}
}

bool app::Game::createEntities()
{
	try
	{
		auto const entities = m_gameFactory.create();

		if constexpr (app::cout::DEBUG_MODE)
		{
			auto text = std::stringstream();
			text << "Created Entities:\n";
			for (auto const& entity : entities) { text << "  [" << entity << "]\n"; }
			cout::wrl(text.str());
		}

		return true;
	}
	catch (std::exception const & e)
	{
		app::cout::wrl({ "Error: ", e.what() });
		return false;
	}
}

bool app::Game::aiTrainingExample()
{
	try
	{
		typedef dlib::matrix<double, 2, 1> SampleType;
		typedef dlib::mlp::kernel_1a_c NeuralNetworkType;

		auto sample = SampleType();
		// Create a multi-layer perceptron network.   This network has 2 nodes on the input layer 
		// (which means it takes column vectors of length 2 as input), 3 nodes in the first 
		// hidden layer, 0 nodes in the second hidden layer and 1 node in the output layer.
		// Note that the other 2 variables in the mlp's constructor are left at their default values.  
		auto neuralNetwork = NeuralNetworkType(2, 3, 0, 1);

		try
		{
			auto file = std::fstream();
			file.open("./res/neural_network.txt", std::ios::in | std::ios::binary);
			if (file.is_open())
			{
				while (file.get());
				dlib::deserialize(neuralNetwork, file);
				file.close();
			}
		}
		catch (std::exception const & e)
		{
			auto temp = NeuralNetworkType(2, 3, 0, 1);
			neuralNetwork.swap(temp);
			app::Console::writeLine();
			app::Console::writeLine({ "Error: [", e.what(), "]" });
		}

		// Now let's put some data into our sample and train on it.  We do this
		// by looping over 41*41 points and labeling them according to their
		// distance from the origin.
		for (std::size_t i = 0; i < 100; ++i)
		{
			for (int r = -20; r <= 20; ++r)
			{
				for (int c = -20; c <= 20; ++c)
				{
					sample(0) = r;
					sample(1) = c;

					auto const & dr = static_cast<double>(r);
					auto const & dc = static_cast<double>(c);
					// if this point is less than 10 from the origin
					if (std::sqrt(dr * dr + dc * dc) <= 10)
					{
						neuralNetwork.train(sample, 1);
					}
					else
					{
						neuralNetwork.train(sample, 0);
					}
				}
			}
		}

		// Now we have trained our mlp.  Let's see how well it did.  
		// Note that if you run this program multiple times you will get different results. This
		// is because the mlp network is randomly initialized.

		// each of these statements prints out the output of the network given a particular sample.

		sample(0) = 3.123;
		sample(1) = 4;
		app::Console::writeLine({ "This sample should be close to 1 and it is classified as a ", std::to_string(neuralNetwork(sample)) });

		sample(0) = 13.123;
		sample(1) = 9.3545;
		app::Console::writeLine({ "This sample should be close to 0 and it is classified as a ", std::to_string(neuralNetwork(sample)) });

		sample(0) = 13.123;
		sample(1) = 0;
		app::Console::writeLine({ "This sample should be close to 0 and it is classified as a ", std::to_string(neuralNetwork(sample)) });

		try
		{
			auto file = std::fstream();
			file.open("./res/neural_network.txt", std::ios::out | std::ios::binary);
			file.write("\0", 1);
			if (file.is_open())
			{
				dlib::serialize(neuralNetwork, file);
				file.close();
			}
		}
		catch (const std::exception& e)
		{
			app::Console::writeLine();
			app::Console::writeLine({ "Error: [", e.what(), "]" });
		}

		return true;
	}
	catch (std::exception const & e)
	{
		app::Console::writeLine({ "ERROR: ", e.what() });
		return false;
	}
}

void app::Game::pollEvents()
{
	for (RenderSystem & renderSystem : m_renderSystems)
		std::visit(util::overload{
			  [this](sys::RenderSystem & sys) { sys.pollEvents(m_keyHandler, m_mouseHandler); }
			, [](auto const & sys) constexpr {}
		}, renderSystem);
}

void app::Game::update(app::time::seconds const & dt)
{
	for (UpdateSystem & updateSystem : m_updateSystems)
		std::visit([&dt](auto & sys) { sys.update(dt); }, updateSystem);
}

void app::Game::render(app::time::seconds const & dt)
{
	for (RenderSystem & renderSystem : m_renderSystems)
		std::visit([&dt](auto & sys) { sys.update(dt); }, renderSystem);
}
