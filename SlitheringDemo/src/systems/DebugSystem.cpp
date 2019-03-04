#include "stdafx.h"
#include "DebugSystem.h"

void app::sys::DebugSystem::init()
{
	app::cout::wrl("Debug system initialized");
}

void app::sys::DebugSystem::update(app::time::nanoseconds const & dt)
{
	app::cout::wrl("Debug system updated");
}
