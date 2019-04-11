#include "stdafx.h"
#include "AiFactory.h"
#include <src/singletons/NeuralNetworkSingleton.h>

// components
#include <src/components/NeuraNetwork.h>

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
		comp::NeuralNetwork::New(*neuralNetwork.pMlp, true);

		neuralNetwork.aiCommands.insert(neuralNetwork.aiCommands.end()
			, m_params.aiCommands.cbegin()
			, m_params.aiCommands.cend());
		neuralNetwork.aiCommands.shrink_to_fit();

		m_registry.assign<decltype(neuralNetwork)>(aiEntity, std::move(neuralNetwork));
	}

	return aiEntity;
}
