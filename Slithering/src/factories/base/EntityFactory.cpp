#include "stdafx.h"
#include "EntityFactory.h"
#include <src/singletons/RegistrySingleton.h>

app::fact::EntityFactory::EntityFactory(Parameters const & params)
	: BaseFactory()
	, m_registry(app::sin::Registry::get())
	, m_params(params)
{
}

app::Entity const app::fact::EntityFactory::create()
{
	return m_params.entity.value_or(m_registry.create());
}
