﻿#ifndef _COMPONENT_INPUT_H
#define _COMPONENT_INPUT_H

#include <src/commands/movement/MoveCommand.h>
#include <src/commands/movement/TurnLeftCommand.h>
#include <src/commands/movement/TurnRightCommand.h>

namespace app::comp
{
	struct Input
	{
	public: // Public Usings/Typedefs/Enums
		using Command = std::variant<
			  com::MoveCommand
			, com::TurnLeftCommand
			, com::TurnRightCommand
		>;
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		using KeyMap = std::map<app::inp::KeyCode, Command>;
		using MouseMap = std::map<app::inp::ButtonCode, Command>;
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		KeyMap keyDownCommands, keyUpCommands, keyPressedCommands;
		MouseMap mouseDownCommands, mouseUpCommands, mousePressedCommands;
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

#endif // !_COMPONENT_INPUT_H
