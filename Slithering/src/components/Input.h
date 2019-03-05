#ifndef _COMPONENT_INPUT_H
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
		struct KeyCommand
		{
			std::vector<app::inp::KeyCode> keys;
			Command command;
		};
		struct MouseCommand
		{
			std::vector<app::inp::ButtonCode> buttons;
			Command command;
		};
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::vector<KeyCommand> keyDownCommands, keyUpCommands, keyPressedCommands;
		std::vector<MouseCommand> mouseDownCommands, mouseUpCommands, mousePressedCommands;
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
