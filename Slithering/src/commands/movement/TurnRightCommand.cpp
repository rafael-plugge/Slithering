#include "stdafx.h"
#include "TurnRightCommand.h"
// components
#include <src/components/Location.h>
#include <src/components/Motion.h>

app::com::TurnRightCommand::TurnRightCommand(app::Entity entity)
	: TurnCommand(entity)
{
}

void app::com::TurnRightCommand::execute() const
{
	auto motionView = s_registry.view<comp::Motion>();
	assert(motionView.contains(m_entity));

	auto & motion = motionView.get(m_entity);

	if (motion.direction.has_value())
	{
		auto & direction = motion.direction.value();
		direction += TurnCommand::TURN_RATE;
	}
	else
	{
		auto view = s_registry.view<comp::Motion, comp::Location>();
		assert(view.contains(m_entity));
		auto & location = view.get<comp::Location>(m_entity);
		location.orientation += TurnCommand::TURN_RATE;
	}
}
