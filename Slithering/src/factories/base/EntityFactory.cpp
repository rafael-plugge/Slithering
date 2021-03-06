﻿#include "stdafx.h"
#include "EntityFactory.h"
#include <src/singletons/RegistrySingleton.h>

app::fact::EntityFactory::EntityFactory(Parameters & params)
	: BaseFactory()
	, m_registry(app::sin::Registry::get())
	, m_params(params)
{
}

app::fact::EntityFactory::EntityFactory(EntityFactory const & other)
	: m_registry(app::sin::Registry::get())
	, m_params(other.m_params)
{
}

app::fact::EntityFactory & app::fact::EntityFactory::operator=(EntityFactory const & other)
{
	return *this;
}

app::Entity const app::fact::EntityFactory::create()
{
	return m_params.entity.has_value()
		? m_params.entity.value()
		: m_params.entity.emplace(m_registry.create());
}
