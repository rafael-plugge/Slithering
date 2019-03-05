#include "stdafx.h"
#include "BaseCommand.h"
#include <src/singletons/RegistrySingleton.h>

app::com::BaseCommand::BaseCommand()
	: m_registry(app::sin::Registry::get())
{
}
