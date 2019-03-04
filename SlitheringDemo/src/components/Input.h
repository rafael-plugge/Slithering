#ifndef _COMPONENT_INPUT_H
#define _COMPONENT_INPUT_H

#include <src/input/Actions.h>

namespace app::comp
{
	struct Input
	{
	public: // Typedefs/Usings
		typedef sf::Keyboard::Key Key;
		typedef std::unordered_map<Key, bool> MapKeysPressed;
		typedef std::unordered_map<app::inp::Actions, MapKeysPressed> MapActionsKeys;
		typedef sf::Mouse::Button Button;
		typedef std::unordered_map<Button, bool> MapButtonsPressed;
		typedef std::unordered_map<app::inp::Actions, MapButtonsPressed> MapActionButtons;
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		MapActionsKeys keys;
		MapActionButtons buttons;
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
