#ifndef _COMPONENT_INPUT_H
#define _COMPONENT_INPUT_H

#include <src/input/Commands.h>

namespace app::comp
{
	struct Input
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::vector<inp::KeyCommand> keyDownCommands, keyUpCommands, keyPressedCommands;
		std::vector<inp::MouseCommand> mouseDownCommands, mouseUpCommands, mousePressedCommands;
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
