#ifndef _INPUT_SYSTEM_H
#define _INPUT_SYSTEM_H

#include <src/systems/BaseSystem.h>

namespace app::sys
{
	class InputSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		InputSystem(inp::Keyhandler & keyHandler, inp::Mousehandler & mouseHandler);

		~InputSystem() = default;

		InputSystem(InputSystem const &) = default;
		InputSystem & operator=(InputSystem const &) = default;

		InputSystem(InputSystem &&) = default;
		InputSystem & operator=(InputSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void init() final override;
		virtual void update(app::time::nanoseconds const & dt) final override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		inp::Keyhandler & m_keyHandler;
		inp::Mousehandler & m_mouseHandler;
	};
}

#endif // !_INPUT_SYSTEM_H
