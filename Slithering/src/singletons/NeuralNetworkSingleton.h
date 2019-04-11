#pragma once

#include <src/components/NeuraNetwork.h>

namespace app::sin
{
	class NeuralNetwork
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		NeuralNetwork() = delete;
		~NeuralNetwork() = delete;

		NeuralNetwork(NeuralNetwork const &) = delete;
		NeuralNetwork & operator=(NeuralNetwork const &) = delete;

		NeuralNetwork(NeuralNetwork &&) = delete;
		NeuralNetwork & operator=(NeuralNetwork &&) = delete;

	public: // Public Static Functions
		static app::comp::NeuralNetwork::Network * const get();
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
		static std::unique_ptr<comp::NeuralNetwork::Network> s_mlp;
	private: // Private Member Variables
	};
}

