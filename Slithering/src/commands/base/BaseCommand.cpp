#include "stdafx.h"
#include "BaseCommand.h"
#include <src/singletons/RegistrySingleton.h>

app::com::BaseCommand::BaseCommand()
	: m_registry(app::sin::Registry::get())
{
}

app::com::BaseCommand::BaseCommand(BaseCommand const & other)
	: m_registry(app::sin::Registry::get())
{
}

app::com::BaseCommand & app::com::BaseCommand::operator=(BaseCommand const & other)
{
	return *this;
}
