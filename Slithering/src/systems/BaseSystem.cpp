#include "stdafx.h"
#include <src/systems/BaseSystem.h>
#include <src/singletons/RegistrySingleton.h>

app::sys::BaseSystem::BaseSystem()
	: m_registry(app::sin::Registry::get())
{
}

app::sys::BaseSystem::BaseSystem(BaseSystem const & other)
	: m_registry(app::sin::Registry::get())
{
}

app::sys::BaseSystem & app::sys::BaseSystem::operator=(BaseSystem const & other)
{
	return *this;
}
