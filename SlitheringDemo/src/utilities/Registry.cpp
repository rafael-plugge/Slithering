#include "stdafx.h"
#include <src/utilities/Registry.h>

std::unique_ptr<app::Registry> app::util::Registry::s_uptrRegistry = nullptr;

app::Registry & app::util::Registry::get()
{
	if (!s_uptrRegistry) { s_uptrRegistry = std::make_unique<app::Registry>(); }
	return *s_uptrRegistry;
}
