#include "stdafx.h"
#include "NeuraNetwork.h"

void app::comp::NeuralNetwork::New(nn::Network & mlp, bool const & restart)
{
	auto defaultMlp = nn::Network(nn::InputLayers, nn::FirstHiddenLayers, nn::SecondHiddenLayers, nn::OutputLayers, nn::Alpha, nn::Momentum);
	if (restart) { mlp.swap(defaultMlp); return; }

	try
	{
		auto file = std::fstream();
		file.open("./res/neural_network.txt", std::ios::in | std::ios::binary);
		if (file.is_open())
		{
			while (file.get());
			dlib::deserialize(mlp, file);
			file.close();
		}
	}
	catch (std::exception const &)
	{
		mlp.swap(defaultMlp);
		return;
	}
}
