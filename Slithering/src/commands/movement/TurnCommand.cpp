#include "stdafx.h"
#include "TurnCommand.h"

app::com::TurnCommand::TurnCommand(app::Entity entity)
	: BaseCommand()
	, m_entity(entity)
{
}
