#include "stdafx.h"
#include "NeuraNetwork.h"

void app::comp::NeuralNetwork::New(Network & mlp, bool const & restart)
{
	auto defaultMlp = Network(InputLayers, FirstHiddenLayers, SecondHiddenLayers, OutputLayers, Alpha, Momentum);
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
