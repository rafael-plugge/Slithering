#pragma once

#include <src/parameters/factories/base/EntityFactoryParameters.h>
#include <src/utilities/NeuralNetworkTypes.h>

namespace app::par::fact::ent
{
	struct TrainingFactoryParameters
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		EntityFactoryParameters entityFactoryParams;
		struct
		{
			math::Vector2f aiLocation;
			std::float_t aiOrientation;
			math::Vector2f foodLocation;
		}input;
		struct
		{
			nn::Type turnLeft;
			nn::Type turnRight;
			nn::Type dontTurn;
		}output;
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
