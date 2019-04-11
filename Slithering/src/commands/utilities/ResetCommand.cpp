#include "stdafx.h"
#include "ResetCommand.h"

// components
#include <src/components/Location.h>

app::com::ResetCommand::ResetCommand(app::Entity const targetEntity, math::Vector2f const & resetPosition)
	: BaseCommand()
	, m_targetEntity(targetEntity)
	, m_resetPosition(resetPosition)
{
}

void app::com::ResetCommand::execute() const
{
	assert(m_registry.valid(m_targetEntity));

	auto & location = m_registry.get<comp::Location>(m_targetEntity);
	location.position = m_resetPosition;
}
