#include "stdafx.h"
#include <src/Game.h>

// systems
#include <src/systems/InputSystem.h>
#include <src/systems/RenderSystem.h>

// factories
#include <src/factories/PlayerFactory.h>

app::Game::Game()
	: m_gameLoop(true)
	, m_registry(app::util::Registry::get())
	, m_updateSystems()
	, m_renderSystems()
	, m_pollEventsSignal()
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
}

app::Game::~Game()
{
}

int app::Game::run()
{
	using clock = std::chrono::high_resolution_clock;
	constexpr app::time::nanoseconds updateStep =
		app::time::toNanos(std::chrono::duration<double, std::milli>(1 / 60.0 * 1000.0));
	clock::time_point deltaTimePoint = clock::now();
	app::time::nanoseconds elapsedTime = updateStep;
	app::time::nanoseconds deltaRenderStep = app::time::nanoseconds::zero();

	if (!this->init()) { return EXIT_FAILURE; }

	while (m_gameLoop)
	{
		this->pollEvents();
		deltaRenderStep =
			(elapsedTime += app::time::toNanos(clock::now() - deltaTimePoint));
		deltaTimePoint = clock::now();
		while (elapsedTime > updateStep)
		{
			this->update(updateStep);
			elapsedTime -= updateStep;
		}
		this->render(deltaRenderStep);
	}

	return EXIT_SUCCESS;
}

bool app::Game::init()
{
	return this->createSystems() && this->createEntities();
}

bool app::Game::createSystems()
{
	try
	{
		m_updateSystems = {
			std::make_unique<sys::InputSystem>(m_keyHandler, m_mouseHandler)
		};

		auto renderSystem = std::make_unique<sys::RenderSystem>();
		m_pollEventsSignal.sink().connect<app::sys::RenderSystem, &app::sys::RenderSystem::pollEvents>(renderSystem.get());
		m_renderSystems = {
			std::move(renderSystem)
		};

		return true;
	}
	catch (std::exception const & e)
	{
		app::Console::writeLine({ "Error: ", e.what() });
		return false;
	}
}

bool app::Game::createEntities()
{
	try
	{
		app::fact::PlayerFactory().create();
		return true;
	}
	catch (std::exception const & e)
	{
		app::Console::writeLine({ "Error: ", e.what() });
		return false;
	}
}

void app::Game::pollEvents()
{
	m_pollEventsSignal.publish(m_keyHandler, m_mouseHandler);
}

void app::Game::update(app::time::nanoseconds const & dt)
{
	for (std::unique_ptr<sys::BaseSystem> & uptrSystem : m_updateSystems) { uptrSystem->update(dt); }
}

void app::Game::render(app::time::nanoseconds const & dt)
{
	std::for_each(m_renderSystems.begin(), m_renderSystems.end(),
		[&dt](std::unique_ptr<sys::BaseSystem> & uptrSystem) { uptrSystem->update(dt); });
}
