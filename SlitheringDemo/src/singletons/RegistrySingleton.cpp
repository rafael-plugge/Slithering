#include "stdafx.h"
#include <src/singletons/RegistrySingleton.h>

std::unique_ptr<app::Registry> app::sin::Registry::s_uptrRegistry = nullptr;

app::Registry & app::sin::Registry::get()
{
	if (!s_uptrRegistry) { s_uptrRegistry = std::make_unique<app::Registry>(); }
	return *s_uptrRegistry;
}
