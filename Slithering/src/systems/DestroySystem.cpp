#include "stdafx.h"
#include "DestroySystem.h"

// components
#include <src/components/Destroy.h>

void app::sys::DestroySystem::init()
{
}

void app::sys::DestroySystem::update(app::time::seconds const & dt)
{
	m_registry.destroy<comp::Destroy>();
}
