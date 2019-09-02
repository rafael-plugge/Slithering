#include "stdafx.h"
#include "NeuralNetworkSingleton.h"

std::shared_ptr<app::nn::Network> app::sin::NeuralNetwork::s_mlp = nullptr;

app::nn::Network * const app::sin::NeuralNetwork::get()
{
	if (!s_mlp)
	{
		s_mlp = std::make_shared<app::nn::Network>(
			  app::nn::InputLayers
			, app::nn::FirstHiddenLayers
			, app::nn::SecondHiddenLayers
			, app::nn::OutputLayers
			, app::nn::Alpha
			, app::nn::Momentum);
	}
	return s_mlp.get();
}
