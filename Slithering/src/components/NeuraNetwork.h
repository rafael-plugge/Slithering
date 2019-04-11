#pragma once

#include <src/input/Commands.h>

namespace app::comp
{
	struct NeuralNetwork
	{
	public: // Public typedefs/usings/enums
		using Type = std::double_t;
		constexpr static long InputLayers = 5L;
		constexpr static long FirstHiddenLayers = 0L;
		constexpr static long SecondHiddenLayers = 0L;
		constexpr static long OutputLayers = 1L;
		constexpr static double Alpha = 0.1;
		constexpr static double Momentum = 0.8;
		using SampleType = dlib::matrix<Type, 5, 1>;
		using Network = dlib::mlp::kernel_1a_c;
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
		static void New(Network & mlp, bool const & restart = true);
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		Network * pMlp;
		std::vector<inp::AiCommand> aiCommands;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}
