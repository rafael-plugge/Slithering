#include "stdafx.h"
#include "BaseSystem.h"

app::sys::BaseSystem::BaseSystem()
	: m_registry(app::util::Registry::get())
{
}
