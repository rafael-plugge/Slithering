#include "stdafx.h"
#include <src/systems/BaseSystem.h>

app::sys::BaseSystem::BaseSystem()
	: m_registry(app::util::Registry::get())
{
}
