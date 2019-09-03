#include "stdafx.h"
#include "AiFactory.h"
#include <src/singletons/NeuralNetworkSingleton.h>
#include <src/singletons/SettingsSingleton.h>

// components
#include <src/components/NeuraNetwork.h>
#include <src/components/Collision.h>

app::fact::ent::AiFactory::AiFactory(Parameters & params)
	: SnakeFactory(params.snakeFactoryParams)
	, m_snakeParams(params.snakeFactoryParams)
	, m_params(params)
{
}

app::Entity const app::fact::ent::AiFactory::create()
{
	app::Entity const aiEntity = SnakeFactory::create();
	auto const& settings = app::sin::Settings::get();

	{
		auto neuralNetwork = comp::NeuralNetwork();
		neuralNetwork.pMlp = app::sin::NeuralNetwork::get();
		comp::NeuralNetwork::New(*neuralNetwork.pMlp, settings.ai.reset);

		neuralNetwork.commands = m_params.commands;

		m_registry.assign<decltype(neuralNetwork)>(aiEntity, std::move(neuralNetwork));
	}
	{
		auto collision = comp::Collision();
		collision.bounds = math::Rectf();
		m_registry.assign<decltype(collision)>(aiEntity, std::move(collision));
	}

	return aiEntity;
}
