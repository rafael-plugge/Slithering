#include "stdafx.h"
#include "MoveCommand.h"

// components
#include <src/components/Location.h>

app::com::MoveCommand::MoveCommand(app::Entity entity, bool moveRight)
	: BaseCommand()
	, m_entity(entity)
	, m_moveRight(moveRight)
{
}

void app::com::MoveCommand::execute() const
{
	auto view = m_registry.view<comp::Location>();
	assert(view.contains(m_entity));
	auto & location = view.get(m_entity);
	if (m_moveRight)
	{
		location.position.x += s_MOVE_AMOUNT;
	}
	else
	{
		location.position.x -= s_MOVE_AMOUNT;
	}
}
