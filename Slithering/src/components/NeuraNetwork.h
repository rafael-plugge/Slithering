#pragma once

#include <src/utilities/NeuralNetworkTypes.h>
#include <src/input/Commands.h>

namespace app::comp
{
	struct NeuralNetwork
	{
	public: // Public typedefs/usings/enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
		static void New(nn::Network & mlp, bool const & restart = true);
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		nn::Network* pMlp;
		std::optional<math::Vector2f> neareastFood;
		std::array<inp::Command, 3> commands;
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
