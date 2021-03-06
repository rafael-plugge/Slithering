﻿#pragma once

#include <src/parameters/factories/entities/SnakeFactoryParameters.h>
#include <src/input/Commands.h>

namespace app::par::fact::ent
{
	struct PlayerFactoryParameters
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::vector<inp::KeyCommand> keyUps, keyDowns, keyPresses;
		std::vector<inp::MouseCommand> mouseUps, mouseDowns, mousePresses;
		SnakeFactoryParameters snakeFactoryParams;
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
