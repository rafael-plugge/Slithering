#ifndef _INPUT_SYSTEM_H
#define _INPUT_SYSTEM_H

#include <src/systems/BaseSystem.h>

namespace app::sys
{
	class InputSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		InputSystem(inp::KeyHandler & keyHandler, inp::MouseHandler & mouseHandler);

		~InputSystem() = default;

		InputSystem(InputSystem const &) = default;
		InputSystem & operator=(InputSystem const &) = default;

		InputSystem(InputSystem &&) = default;
		InputSystem & operator=(InputSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void init() final override;
		virtual void update(app::time::seconds const & dt) final override;
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
		inp::KeyHandler & m_keyHandler;
		inp::MouseHandler & m_mouseHandler;
	};
}

#endif // !_INPUT_SYSTEM_H
