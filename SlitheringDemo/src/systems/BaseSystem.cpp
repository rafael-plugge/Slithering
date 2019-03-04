#include "stdafx.h"
#include <src/systems/BaseSystem.h>
#include <src/singletons/RegistrySingleton.h>

app::sys::BaseSystem::BaseSystem()
	: m_registry(app::sin::Registry::get())
{
}
