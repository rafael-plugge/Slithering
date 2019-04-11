#include "stdafx.h"
#include "SpeedCommand.h"

// components
#include <src/components/Motion.h>

app::com::SpeedCommand::SpeedCommand(app::Entity targetEntity, std::float_t speedIncrements)
	: BaseCommand()
	, m_targetEntity(targetEntity)
	, m_speedIncrements(speedIncrements)
{
}

void app::com::SpeedCommand::execute() const
{
	assert(m_registry.valid(m_targetEntity));
	auto motionView = m_registry.view<comp::Motion>();
	assert(motionView.contains(m_targetEntity));

	auto & motion = motionView.get(m_targetEntity);
	motion.speed += m_speedIncrements;
}
