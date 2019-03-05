#include "stdafx.h"
#include "TurnLeftCommand.h"
// components
#include <src/components/Location.h>
#include <src/components/Motion.h>

app::com::TurnLeftCommand::TurnLeftCommand(app::Entity entity)
	: TurnCommand(entity)
{
}

void app::com::TurnLeftCommand::execute() const
{
	auto motionView = m_registry.view<comp::Motion>();
	assert(motionView.contains(m_entity));

	auto & motion = motionView.get(m_entity);

	if (motion.direction.has_value())
	{
		auto & direction = motion.direction.value();
		direction -= TurnCommand::TURN_RATE;
	}
	else
	{
		auto view = m_registry.view<comp::Motion, comp::Location>();
		assert(view.contains(m_entity));
		auto & location = view.get<comp::Location>(m_entity);
		location.orientation -= TurnCommand::TURN_RATE;
	}
}
