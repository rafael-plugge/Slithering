#include "stdafx.h"
#include "NeuralNetworkSingleton.h"

std::unique_ptr<app::comp::NeuralNetwork::Network> app::sin::NeuralNetwork::s_mlp = nullptr;

app::comp::NeuralNetwork::Network * const app::sin::NeuralNetwork::get()
{
	using NeuralNetwork = app::comp::NeuralNetwork;
	if (!s_mlp)
	{
		s_mlp = std::make_unique<NeuralNetwork::Network>(
			  NeuralNetwork::InputLayers
			, NeuralNetwork::FirstHiddenLayers
			, NeuralNetwork::SecondHiddenLayers
			, NeuralNetwork::OutputLayers
			, NeuralNetwork::Alpha
			, NeuralNetwork::Momentum);
	}
	return s_mlp.get();
}
