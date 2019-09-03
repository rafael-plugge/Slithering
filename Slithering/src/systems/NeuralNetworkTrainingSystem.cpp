#include "stdafx.h"
#include <src/systems/NeuralNetworkTrainingSystem.h>
#include <src/utilities/NeuralNetworkTypes.h>
#include <src/singletons/SettingsSingleton.h>
#include <src/math/Math.h>

// components
#include <src/components/Location.h>
#include <src/components/NeuraNetwork.h>
#include <src/components/TrainingSet.h>

app::sys::NeuralNetworkTrainingSystem::NeuralNetworkTrainingSystem(bool& keepTraining)
	: BaseSystem()
	, m_keepTraining(keepTraining)
	, m_train()
	, m_counter(0L)
{
}

void app::sys::NeuralNetworkTrainingSystem::init()
{
	auto const& settings = app::sin::Settings::get();
	m_train.emplace(settings.ai.train);
	m_trainingEdge = { 500.0f, 500.0f };
	m_positionSkipRate = 50.0f;
	m_foodRegion = { 500.0f, 500.0f };
	m_foodSkipRate = 50.0f;
	m_angleSkipRate = 10.0f;
}

void app::sys::NeuralNetworkTrainingSystem::update(app::time::seconds const& dt)
{
	if (!m_train.value_or(false)) { return; }

	app::cout::wrl("--------------Training Start--------------");
	app::cout::wrl();
	auto const& maximumTrainingLoops = app::sin::Settings::get().ai.howMany;
	m_registry.view<comp::NeuralNetwork>()
		.each([&, this](app::Entity const entity, comp::NeuralNetwork& nn)
	{
		std::cout << "Training Counter: " << m_counter << std::endl;
		if (m_counter > maximumTrainingLoops) { return; }
		foodDataLoop(*nn.pMlp);
		++m_counter;
	});
	m_keepTraining = !(m_counter > maximumTrainingLoops);
}

void app::sys::NeuralNetworkTrainingSystem::deinit()
{
	if (!m_train.value_or(false)) { return; }

	m_registry.view<comp::NeuralNetwork>()
		.each([&, this](app::Entity const entity, comp::NeuralNetwork const& nn)
	{
		nn::Network const& mlp = *nn.pMlp;
		
		try
		{
			auto file = std::fstream();
			file.open("./res/neural_network.txt", std::ios::out | std::ios::binary);
			file.write("\0", 1);
			if (file.is_open())
			{
				dlib::serialize(mlp, file);
				file.close();
			}
		}
		catch (std::exception const& e)
		{
			app::cout::wrl({ "Error: [", e.what(), "]" });
		}
	});
}

app::sys::NeuralNetworkTrainingSystem::CommandDirection app::sys::NeuralNetworkTrainingSystem::getCorrectDirection(math::Vector2f const& position, float const& dir, math::Vector2f const& foodLocation)
{
		std::float_t constexpr MARGIN_OF_ERROR = 1.0f; // don't turn if food is within a field of view of 1 degree.
		std::optional<bool> turnLeft = std::nullopt;

		math::Vector2f const& fsmDirectionVector = math::toVector(dir);
		math::Vector2f const& foodDirectionVector = position - foodLocation;

		auto const& foodDirectionVectorUnit = foodDirectionVector.unit();

		float const& angleBetweenFsmFood = math::angleBetween(fsmDirectionVector, foodDirectionVector);

		if (angleBetweenFsmFood > MARGIN_OF_ERROR)
			turnLeft.emplace(true);
		else if (angleBetweenFsmFood < -MARGIN_OF_ERROR)
			turnLeft.emplace(false);
		else
			turnLeft.reset();

		if (turnLeft && turnLeft.value()) // turn left
			return CommandDirection::Left;
		else if (turnLeft && !turnLeft.value()) // turn right
			return CommandDirection::Right;
		else // don't turn
			return CommandDirection::Straight;
}

std::array<app::nn::Type, 3> app::sys::NeuralNetworkTrainingSystem::generateOutput(CommandDirection const& dir)
{
	switch (dir)
	{
	case CommandDirection::Left:
		return { 1, 0, 0 };
	case CommandDirection::Right:
		return { 0, 1, 0 };
	case CommandDirection::Straight:
	default:
		return { 0, 0, 1 };
	}
}

app::sys::NeuralNetworkTrainingSystem::TrainingSet app::sys::NeuralNetworkTrainingSystem::readyData(
	math::Vector2f const& pos, float const& dir, math::Vector2f const& foodLocation, std::array<nn::Type, 3> const& response)
{
	auto set = TrainingSet();

	set.input.aiLocation = pos;
	set.input.aiOrientation = dir;
	set.input.foodLocation = foodLocation;
	set.output.turnLeft = response.at(0);
	set.output.turnRight = response.at(1);
	set.output.dontTurn = response.at(2);

	return std::move(set);
}

void app::sys::NeuralNetworkTrainingSystem::positionDataLoop(nn::Network& nn, math::Vector2f const& foodLocation)
{
	auto pos = math::Vector2f{ 0.0f, 0.0f };
	float dir = 0.0f;
	for (pos.x = -m_trainingEdge.x; pos.x < m_trainingEdge.x; pos.x += m_positionSkipRate)
	{
		for (pos.y = -m_trainingEdge.y; pos.y < m_trainingEdge.y; pos.y += m_positionSkipRate)
		{
			if (pos == 0.0f || pos == foodLocation) { continue; }
			for (float dir = -90.0f; dir <= 180.0f; dir += m_angleSkipRate)
			{
				TrainingSet const& set = readyData(pos, dir, foodLocation, generateOutput(getCorrectDirection(pos, dir, foodLocation)));
				nn::InputData const& input = set.input;
				nn::OutputData const& output = set.output;
				nn.train(input, output);
			}
		}
	}
}

void app::sys::NeuralNetworkTrainingSystem::foodDataLoop(nn::Network& nn)
{
	auto food = math::Vector2f{ 0.0f, 0.0f };
	for (food.x = -m_foodRegion.x; food.x < m_foodRegion.x; food.x += m_foodSkipRate)
		for (food.y = -m_foodRegion.y; food.y < m_foodRegion.y; food.y += m_foodSkipRate)
			if (food != 0.0f) { this->positionDataLoop(nn, food); }
}
