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

void app::sys::InputSystem::update(app::time::seconds const & dt)
{
	constexpr auto visitor = [](auto const & com) constexpr -> void { com.execute(); };
	m_registry.view<comp::Input>()
		.each([&, this](app::Entity const entity, comp::Input & input) -> void
	{
		for (auto const & keyCommand : input.keyUpCommands)
			for (auto const & key : keyCommand.keys)
				if (m_keyHandler.isKeyUp(key)) { std::visit(visitor, keyCommand.command); break; }
		for (auto const & keyCommand : input.keyDownCommands)
			for (auto const & key : keyCommand.keys)
				if (m_keyHandler.isKeyDown(key)) { std::visit(visitor, keyCommand.command); break; }
		for (auto const & keyCommand : input.keyPressedCommands)
			for (auto const & key : keyCommand.keys)
				if (m_keyHandler.isKeyPressed(key)) { std::visit(visitor, keyCommand.command); break; }

		for (auto const & buttonCommand : input.mouseUpCommands)
			for (auto const & button : buttonCommand.buttons)
				if (m_mouseHandler.isButtonUp(button)) { std::visit(visitor, buttonCommand.command); break; }
		for (auto const & buttonCommand : input.mouseDownCommands)
			for (auto const & button : buttonCommand.buttons)
				if (m_mouseHandler.isButtonDown(button)) { std::visit(visitor, buttonCommand.command); break; }
		for (auto const & buttonCommand : input.mousePressedCommands)
			for (auto const & button : buttonCommand.buttons)
				if (m_mouseHandler.isButtonPressed(button)) { std::visit(visitor, buttonCommand.command); break; }
	});

	m_keyHandler.update();
	m_mouseHandler.update();
}
