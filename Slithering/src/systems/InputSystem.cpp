#include "stdafx.h"
#include <src/systems/InputSystem.h>

// Components
#include <src/components/Input.h>
#include <src/components/Commandable.h>

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
	m_registry.view<comp::Input, comp::Commandable>()
		.each([&, this](app::Entity const entity, comp::Input & input, comp::Commandable & commandable) -> void
	{
		auto const forwardCommand = inp::Command(std::in_place_type<com::ForwardCommand>, entity);
		for (auto const & keyCommand : input.keyUpCommands)
			for (auto const & key : keyCommand.inputs)
				if (m_keyHandler.isKeyUp(key)) { commandable.runOnce.push({ forwardCommand, keyCommand.command }); break; }
		for (auto const & keyCommand : input.keyDownCommands)
			for (auto const & key : keyCommand.inputs)
				if (m_keyHandler.isKeyDown(key)) { commandable.runOnce.push({ forwardCommand, keyCommand.command }); break; }
		for (auto const & keyCommand : input.keyPressedCommands)
			for (auto const & key : keyCommand.inputs)
				if (m_keyHandler.isKeyPressed(key)) { commandable.runOnce.push({ forwardCommand, keyCommand.command }); break; }

		for (auto const & buttonCommand : input.mouseUpCommands)
			for (auto const & button : buttonCommand.inputs)
				if (m_mouseHandler.isButtonUp(button)) { commandable.runOnce.push({ forwardCommand, buttonCommand.command }); break; }
		for (auto const & buttonCommand : input.mouseDownCommands)
			for (auto const & button : buttonCommand.inputs)
				if (m_mouseHandler.isButtonDown(button)) { commandable.runOnce.push({ forwardCommand, buttonCommand.command }); break; }
		for (auto const & buttonCommand : input.mousePressedCommands)
			for (auto const & button : buttonCommand.inputs)
				if (m_mouseHandler.isButtonPressed(button)) { commandable.runOnce.push({ buttonCommand.command }); break; }

		commandable.runOnce.push({ forwardCommand });
	});

	m_keyHandler.update();
	m_mouseHandler.update();
}
