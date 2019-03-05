#include "stdafx.h"
#include "TurnCommand.h"
#include <src/components/Location.h>

app::com::TurnCommand::TurnCommand(app::Entity entity)
	: BaseCommand()
	, m_entity(entity)
{
}
