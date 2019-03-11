#include "stdafx.h"
#include <src/systems/BaseSystem.h>
#include <src/singletons/RegistrySingleton.h>

app::Registry & app::sys::BaseSystem::s_registry = app::sin::Registry::get();
