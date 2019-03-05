#include "stdafx.h"
#include "TurnRightCommand.h"
// components
//#include <src/components/Motion.h>

app::com::TurnRightCommand::TurnRightCommand(app::Entity entity)
	: TurnCommand(entity)
{
}

void app::com::TurnRightCommand::execute() const
{
	auto view = m_registry.view<int>();
	assert(view.contains(m_entity));
}
