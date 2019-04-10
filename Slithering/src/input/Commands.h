#ifndef _INPUT_COMMANDS_H
#define _INPUT_COMMANDS_H

#include <src/commands/base/DefaultCommand.h>
#include <src/commands/movement/MoveCommand.h>
#include <src/commands/movement/TurnLeftCommand.h>
#include <src/commands/movement/TurnRightCommand.h>
#include <src/commands/movement/ForwardCommand.h>
#include <src/commands/debug/ResetCommand.h>

namespace app::inp
{
	using Command = std::variant<
		  com::DefaultCommand
		, com::MoveCommand
		, com::TurnLeftCommand
		, com::TurnRightCommand
		, com::ForwardCommand
		, com::ResetCommand
	>;

	template<typename _InputCode>
	struct InputCommand
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::vector<_InputCode> inputs;
		Command command;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	using KeyCommand = InputCommand<app::inp::KeyCode>;
	static_assert(std::is_default_constructible<KeyCommand>::value, "KeyCommand must be default constructible");
	static_assert(std::is_destructible<KeyCommand>::value, "KeyCommand must be destructible");
	static_assert(std::is_copy_constructible<KeyCommand>::value, "KeyCommand must be copy constructible");
	static_assert(std::is_copy_assignable<KeyCommand>::value, "KeyCommand must be copy assignable");
	static_assert(std::is_move_constructible<KeyCommand>::value, "KeyCommand must be move constructible");
	static_assert(std::is_move_assignable<KeyCommand>::value, "KeyCommand must be move assignable");

	using MouseCommand = InputCommand<app::inp::ButtonCode>;
	static_assert(std::is_default_constructible<MouseCommand>::value, "MouseCommand must be default constructible");
	static_assert(std::is_destructible<MouseCommand>::value, "MouseCommand must be destructible");
	static_assert(std::is_copy_constructible<MouseCommand>::value, "MouseCommand must be copy constructible");
	static_assert(std::is_copy_assignable<MouseCommand>::value, "MouseCommand must be copy assignable");
	static_assert(std::is_move_constructible<MouseCommand>::value, "MouseCommand must be move constructible");
	static_assert(std::is_move_assignable<MouseCommand>::value, "MouseCommand must be move assignable");
}

#endif // !_INPUT_COMMANDS_H
