#include "stdafx.h"
#include "CameraFactory.h"

// components
#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Camera.h>

app::fact::ent::CameraFactory::CameraFactory(Parameters & params)
	: EntityFactory(params.entityFactoryParams)
	, m_params(params)
{
}

app::Entity const app::fact::ent::CameraFactory::create()
{
	app::Entity const entity = EntityFactory::create();

	auto location = comp::Location();
	location.position = m_params.position;
	location.orientation = 0.0f;
	m_registry.assign<decltype(location)>(entity, std::move(location));

	auto dimensions = comp::Dimension();
	dimensions.size = m_params.size;
	dimensions.origin = dimensions.size / 2.0f;
	m_registry.assign<decltype(dimensions)>(entity, std::move(dimensions));

	auto camera = comp::Camera();
	camera.target = m_params.target;
	camera.viewport = m_params.viewport;
	camera.baseIndex = m_params.baseIndex;
	m_registry.assign<decltype(camera)>(entity, std::move(camera));

	return entity;
}
