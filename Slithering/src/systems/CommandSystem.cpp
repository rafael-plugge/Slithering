#include "stdafx.h"
#include "CommandSystem.h"
#include <src/utilities/Variant.h>
// components
#include <src/components/Commandable.h>
#include <src/components/Segment.h>

void app::sys::CommandSystem::init()
{
}

void app::sys::CommandSystem::update(app::time::seconds const & dt)
{
	constexpr auto visitor = [](auto const & com) constexpr -> void { com.execute(); };
	auto segmentView = m_registry.view<comp::Commandable, comp::Segment>();
	m_registry.view<comp::Commandable>()
		.each([&, this](app::Entity const entity, comp::Commandable & commandable)
	{
		if (!commandable.loop.empty())
		{
			//for (auto const & command : commandable.loop) { std::visit(visitor, command); }
		}
		if (!commandable.runOnce.empty())
		{
			auto & commands = commandable.runOnce.front();
			for (auto const & command : commands) { std::visit(visitor, command); }
			if (segmentView.contains(entity))
			{
				auto const & segment = segmentView.get<comp::Segment>(entity);
				if (segment.child.has_value() && segmentView.contains(segment.child.value()))
				{
					auto & childCommandable = segmentView.get<comp::Commandable>(segment.child.value());

					auto childCommand = std::vector<inp::Command>();
					for (auto const & command : commands)
					{
						std::visit(util::overload{
							  [&](app::com::TurnLeftCommand const & com) { childCommand.push_back(inp::Command(std::in_place_type<com::TurnLeftCommand>, segment.child.value())); }
							, [&](app::com::TurnRightCommand const & com) { childCommand.push_back(inp::Command(std::in_place_type<com::TurnRightCommand>, segment.child.value())); }
							, [&](app::com::ForwardCommand const & com) { childCommand.push_back(inp::Command(std::in_place_type<com::ForwardCommand>, segment.child.value())); }
							, [](auto const & com) {}
						}, command);
					}
					childCommandable.runOnce.push(std::move(childCommand));
				}
			}
			commandable.runOnce.pop();
		}
	});
}
