#include "stdafx.h"
#include <src/systems/NeuralNetworkTrainingSystem.h>
#include <src/utilities/NeuralNetworkTypes.h>
#include <src/singletons/SettingsSingleton.h>

// components
#include <src/components/Location.h>
#include <src/components/NeuraNetwork.h>
#include <src/components/TrainingSet.h>

app::sys::NeuralNetworkTrainingSystem::NeuralNetworkTrainingSystem(bool& signalEnd)
	: BaseSystem()
	, m_signalEnd(signalEnd)
	, m_train()
	, m_counter(0L)
{
}

void app::sys::NeuralNetworkTrainingSystem::init()
{
	auto const& settings = app::sin::Settings::get();
	m_train.emplace(settings.ai.train);
}

void app::sys::NeuralNetworkTrainingSystem::update(app::time::seconds const& dt)
{
	if (!m_train.value_or(false)) { return; }

	auto const& maximumTrainingLoops = app::sin::Settings::get().ai.howMany;
	m_registry.view<comp::NeuralNetwork>()
		.each([&, this](app::Entity const entity, comp::NeuralNetwork& nn)
	{
		nn::Network& mlp = *nn.pMlp;

		if (m_counter > maximumTrainingLoops) { return; }
		m_registry.view<comp::TrainingSet>()
			.each([&, this](app::Entity const trainingEntity, comp::TrainingSet const& set)
		{
			if (m_counter > maximumTrainingLoops) { return; }
			nn::InputData const& input = set.input;
			nn::OutputData const& output = set.output;
			mlp.train(input, output);
			++m_counter;
		});
	});
	m_signalEnd = m_counter > maximumTrainingLoops;
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
