#include "stdafx.h"
#include <src/factories/entities/WorldFactory.h>

// tags
#include <src/tags/World.h>

// utilities
#include <src/utilities/Range.h>

app::fact::ent::WorldFactory::WorldFactory(Parameters & params)
	: BorderFactory(params.borderFactoryParams)
	, m_params(params)
	, m_borderParams(params.borderFactoryParams)
	, m_imageParams(m_borderParams.imageFactoryParams)
	, m_entityParams(m_imageParams.entityFactoryParams)
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

	this->createBorders();

	return worldEntity;
}

void app::fact::ent::WorldFactory::createBorders()
{
	auto const & HALF_SIZE = m_params.bounds.halfSize();
	auto const & CENTER = m_params.bounds.center();
	auto const & THICKNESS = m_params.borderFactoryParams.thickness;
	auto const & LEFT = math::Vector2f{ CENTER.x - HALF_SIZE.x, CENTER.y };
	auto const & TOP = math::Vector2f{ CENTER.x, CENTER.y - HALF_SIZE.y };
	auto const & RIGHT = math::Vector2f{ CENTER.x + HALF_SIZE.x - THICKNESS, CENTER.y };
	auto const & BOTTOM = math::Vector2f{ CENTER.x, CENTER.y + HALF_SIZE.y - THICKNESS };
	m_imageParams.size = { m_borderParams.thickness, m_params.bounds.h };
	m_imageParams.origin = m_imageParams.size / 2.0f;

	// left-side
	{
		m_entityParams.entity.reset();
		m_imageParams.position = LEFT;
		m_imageParams.orientation = 0.0f;
		BorderFactory::create();
	}
	// top-side
	{
		m_entityParams.entity.reset();
		m_imageParams.position = TOP;
		m_imageParams.orientation = 90.0f;
		BorderFactory::create();
	}
	// right-side
	{
		m_entityParams.entity.reset();
		m_imageParams.position = RIGHT;
		m_imageParams.orientation = 0.0f;
		BorderFactory::create();
	}
	// bottom-side
	{
		m_entityParams.entity.reset();
		m_imageParams.position = BOTTOM;
		m_imageParams.orientation = 90.0f;
		BorderFactory::create();
	}
}
