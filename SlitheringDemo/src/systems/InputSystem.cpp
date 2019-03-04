#include "stdafx.h"
#include <src/systems/InputSystem.h>

// Components
#include <src/components/Input.h>

app::sys::InputSystem::InputSystem(inp::Keyhandler & keyHandler, inp::Mousehandler & mouseHandler)
	: m_keyHandler(keyHandler)
	, m_mouseHandler(mouseHandler)
{
}

void app::sys::InputSystem::init()
{
}

void app::sys::InputSystem::update(app::time::nanoseconds const & dt)
{
	m_registry.view<comp::Input>()
		.each([&dt, this](app::Entity const entity, comp::Input & input) -> void
	{
		for (auto &[action, keyPressedMap] : input.keys)
		{
			for (auto &[key, pressed] : keyPressedMap)
			{
				pressed = m_keyHandler.isKeyDown(key);
			}
		}
		for (auto &[action, buttonPressedMap] : input.buttons)
		{
			for (auto &[button, pressed] : buttonPressedMap)
			{
				pressed = m_mouseHandler.isButtonDown(button);
			}
		}
	});

	m_keyHandler.update();
	m_mouseHandler.update();
}
