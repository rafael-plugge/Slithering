#pragma once

namespace app::nn
{
	using Type = std::double_t;
	// Input Layers
	// Position X Y 1 2
	// Orientation 3
	// Closest Food Position X Y 4 5
	constexpr static long InputLayers = 5L;
	constexpr static long FirstHiddenLayers = 0L;
	constexpr static long SecondHiddenLayers = 0L;
	constexpr static long OutputLayers = 3L;
	constexpr static double Alpha = 0.1;
	constexpr static double Momentum = 0.8;
	using InputData = dlib::matrix<Type, InputLayers, 1L>;
	using OutputData = dlib::matrix<Type, OutputLayers, 1L>;
	using Network = dlib::mlp::kernel_1a_c;
}
