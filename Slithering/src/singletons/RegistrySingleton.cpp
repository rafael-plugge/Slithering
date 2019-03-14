#include "stdafx.h"
#include <src/singletons/RegistrySingleton.h>

std::shared_ptr<app::Registry> app::sin::Registry::s_uptrRegistry = app::sin::Registry::s_uptrRegistry
	? app::sin::Registry::s_uptrRegistry
	: std::make_shared<app::Registry>();

app::Registry & app::sin::Registry::get()
{
	if (!s_uptrRegistry) { s_uptrRegistry = std::make_unique<app::Registry>(); }
	return *s_uptrRegistry;
}
