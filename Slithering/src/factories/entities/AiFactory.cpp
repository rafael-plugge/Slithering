#include "stdafx.h"
#include "AiFactory.h"
#include <src/singletons/NeuralNetworkSingleton.h>

// components
#include <src/components/NeuraNetwork.h>
#include <src/components/Commandable.h>

app::fact::ent::AiFactory::AiFactory(Parameters & params)
	: SnakeFactory(params.snakeFactoryParams)
	, m_snakeParams(params.snakeFactoryParams)
	, m_params(params)
{
}

app::Entity const app::fact::ent::AiFactory::create()
{
	app::Entity const aiEntity = SnakeFactory::create();

	{
		auto neuralNetwork = comp::NeuralNetwork();
		neuralNetwork.pMlp = app::sin::NeuralNetwork::get();
		comp::NeuralNetwork::New(*neuralNetwork.pMlp, false);

		neuralNetwork.commands = m_params.commands;

		m_registry.assign<decltype(neuralNetwork)>(aiEntity, std::move(neuralNetwork));
	}

	return aiEntity;
}
