#ifndef _MOUSE_HANDLER_H
#define _MOUSE_HANDLER_H

#include "math/Vector2.h"

namespace app::inp
{
	class MouseHandler
	{
	public: // Public enum
		using ButtonType = sf::Mouse::Button;
	private: // Private typedefs
		typedef std::map<const ButtonType, bool> map;
	public: // Constructors/Destructor/Assignments
		MouseHandler() = default;
		MouseHandler(MouseHandler const &) = default;
		MouseHandler(MouseHandler &&) = default;

		~MouseHandler() = default;

		MouseHandler & operator=(MouseHandler const &) = default;
		MouseHandler & operator=(MouseHandler &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		void updateButton(std::uint8_t const & buttonIndex, bool const & pressed);
		void updatePosition(std::int32_t const & x, std::int32_t const & y);

		bool isButtonDown(ButtonType const & button) const;
		bool isButtonDown(std::initializer_list<ButtonType> const & buttons) const;
		bool isButtonUp(ButtonType const & button) const;
		bool isButtonUp(std::initializer_list<ButtonType> const & buttons) const;
		bool isButtonPressed(ButtonType const & button) const;
		bool isButtonPressed(std::initializer_list<ButtonType> const & buttons) const;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
		static bool isButtonDown(map const & keyMap, ButtonType const & button);
		static bool isButtonDown(map const & keyMap, std::initializer_list<ButtonType> const & buttons);
		static bool isButtonUp(map const & keyMap, ButtonType const & button);
		static bool isButtonUp(map const & keyMap, std::initializer_list<ButtonType> const & buttons);
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		map m_keyNowMap;
		map m_keyPrevMap;
		math::Vector2i m_mouse;
	};
}

#endif // !_MOUSE_HANDLER_H
