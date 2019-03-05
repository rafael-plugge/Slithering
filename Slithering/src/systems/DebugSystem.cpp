#include "stdafx.h"
#include "DebugSystem.h"

void app::sys::DebugSystem::init()
{
	if constexpr (DEBUG_MODE)
	{
		app::cout::wrl("Debug system initialized");
	}
}

void app::sys::DebugSystem::update(app::time::seconds const & dt)
{
	if constexpr (DEBUG_MODE)
	{
		app::cout::wrl("Debug system updated");
	}
}
