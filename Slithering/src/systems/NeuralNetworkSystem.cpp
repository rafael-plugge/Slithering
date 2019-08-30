#include "stdafx.h"
#include "NeuralNetworkSystem.h"

#include <src/tags/Player.h>
// components
#include <src/components/Location.h>
#include <src/components/Food.h>
#include <src/components/NeuraNetwork.h>

void app::sys::NeuralNetworkSystem::init()
{
}

void app::sys::NeuralNetworkSystem::update(app::time::seconds const & dt)
{
	auto input = comp::NeuralNetwork::SampleType();

	constexpr auto visitor = [](auto const & com) constexpr -> void { com.execute(); };
	m_registry.view<comp::NeuralNetwork>()
		.each([&, this](app::Entity const entity, comp::NeuralNetwork & neuralNetwork)
	{
		comp::NeuralNetwork::Network & mlp = *neuralNetwork.pMlp;
		for (auto const & command : neuralNetwork.aiCommands)
			if (mlp(input) > 0.1) { std::visit(visitor, command.command); }
	});
}
