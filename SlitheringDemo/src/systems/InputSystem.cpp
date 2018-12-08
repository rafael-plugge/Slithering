#include "stdafx.h"
#include <src/systems/InputSystem.h>

app::sys::InputSystem::InputSystem(inp::Keyhandler & keyHandler, inp::Mousehandler & mouseHandler)
	: m_keyHandler(keyHandler)
	, m_mouseHandler(mouseHandler)
{
}

void app::sys::InputSystem::update(app::time::nanoseconds const & dt)
{
	m_registry
		.each([&dt](app::Entity const entity) {});

	m_keyHandler.update();
	m_mouseHandler.update();
}
