﻿#pragma once

#include <src/parameters/factories/entities/SnakeFactoryParameters.h>
#include <src/input/Commands.h>

namespace app::par::fact::ent
{
	struct AiFactoryParameters
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		SnakeFactoryParameters snakeFactoryParams;
		std::array<inp::AiCommand, 3> aiCommands;
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
