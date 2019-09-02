#pragma once

#include <src/utilities/NeuralNetworkTypes.h>

namespace app::comp
{
	struct TrainingSet
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		struct
		{
			math::Vector2f aiLocation;
			std::float_t aiOrientation;
			math::Vector2f foodLocation;

			operator nn::InputData() const
			{
				auto data = nn::InputData();
				data = aiLocation.x, aiLocation.y
					, aiOrientation
					, foodLocation.x, foodLocation.y;
				return data;
			}
		}input;
		struct
		{
			nn::Type turnLeft;
			nn::Type turnRight;
			nn::Type dontTurn;

			operator nn::OutputData() const
			{
				auto data = nn::OutputData();
				data = turnLeft
					, turnRight
					, dontTurn;
				return data;
			}
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
