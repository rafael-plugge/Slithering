#include "stdafx.h"
#include "BaseCommand.h"
#include <src/singletons/RegistrySingleton.h>

app::Registry & app::com::BaseCommand::s_registry = app::sin::Registry::get();
