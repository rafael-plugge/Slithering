#include "stdafx.h"
#include <src/factories/EntityFactory.h>
#include <src/utilities/Registry.h>

app::fact::EntityFactory::EntityFactory()
	: m_registry(app::util::Registry::get())
{
}
