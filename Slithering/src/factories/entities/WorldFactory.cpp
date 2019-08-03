#include "stdafx.h"
#include <src/factories/entities/WorldFactory.h>

// tags
#include <src/tags/World.h>

app::fact::ent::WorldFactory::WorldFactory(Parameters & params)
	: EntityFactory(params.entityFactoryParams)
	, m_params(params)
	, m_entityParams(params.entityFactoryParams)
{
}

app::Entity const app::fact::ent::WorldFactory::create()
{
	assert(!m_registry.has<tags::World>()); //Existing tag has been detected. Tags can only ever be created once.
	app::Entity const worldEntity = EntityFactory::create();

	{
		auto world = tags::World();
		world.bounds = m_params.bounds;
		m_registry.assign<tags::World>(entt::tag_t{}, worldEntity, std::move(world));
	}

	return worldEntity;
}
