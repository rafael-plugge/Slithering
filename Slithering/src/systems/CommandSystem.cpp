#include "stdafx.h"
#include <src/systems/CommandSystem.h>

// components
#include <src/components/Commandable.h>

void app::sys::CommandSystem::init()
{
}

void app::sys::CommandSystem::update(app::time::seconds const& dt)
{
	constexpr auto visitor = [](auto const& com) constexpr -> void { com.execute(); };

	m_registry.view<comp::Commandable>()
		.each([&](app::Entity const entity, comp::Commandable& commandable) -> void
	{
		for (auto const& command : commandable.loop) { std::visit(visitor, command); }

		if (commandable.runOnce.size() == 0) { return; }
		for (auto const& command : commandable.runOnce.front()) { std::visit(visitor, command); }
		commandable.runOnce.pop();
	});
}
