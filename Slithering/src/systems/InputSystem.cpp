#include "stdafx.h"
#include <src/systems/InputSystem.h>

// Components
#include <src/components/Input.h>

app::sys::InputSystem::InputSystem(inp::KeyHandler & keyHandler, inp::MouseHandler & mouseHandler)
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
		for (auto const &[key, command] : input.keyUpCommands)
			if (m_keyHandler.isKeyUp(key)) { std::visit([](auto const & com) { com.execute(); }, command); }
		for (auto const &[key, command] : input.keyDownCommands)
			if (m_keyHandler.isKeyDown(key)) { std::visit([](auto const & com) { com.execute(); }, command); }
		for (auto const &[key, command] : input.keyPressedCommands)
			if (m_keyHandler.isKeyPressed(key)) { std::visit([](auto const & com) { com.execute(); }, command); }
		for (auto const &[button, command] : input.mouseUpCommands)
			if (m_mouseHandler.isButtonUp(button)) { std::visit([](auto const & com) { com.execute(); }, command); }
		for (auto const &[button, command] : input.mouseDownCommands)
			if (m_mouseHandler.isButtonDown(button)) { std::visit([](auto const & com) { com.execute(); }, command); }
		for (auto const &[button, command] : input.mousePressedCommands)
			if (m_mouseHandler.isButtonPressed(button)) { std::visit([](auto const & com) { com.execute(); }, command); }
	});

	m_keyHandler.update();
	m_mouseHandler.update();
}
