#include "stdafx.h"
#include "ImageFactory.h"

// components
#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Layer.h>
#include <src/components/Render.h>

app::fact::ent::ImageFactory::ImageFactory(Parameters const & params)
	: EntityFactory(params)
	, m_params(params)
{
}

app::Entity const app::fact::ent::ImageFactory::create()
{
	app::Entity const imageEntity = EntityFactory::create();

	auto location = comp::Location();
	location.position = m_params.position;
	location.orientation = m_params.orientation;
	m_registry.assign<decltype(location)>(imageEntity, std::move(location));

	auto dimensions = comp::Dimension();
	dimensions.size = m_params.size;
	dimensions.origin = m_params.origin;
	m_registry.assign<decltype(dimensions)>(imageEntity, std::move(dimensions));

	auto layer = comp::Layer();
	layer.zIndex = m_params.zIndex;
	m_registry.assign<decltype(layer)>(imageEntity, std::move(layer));

	auto render = comp::Render();
	render.fill = m_params.fill;
	render.source = m_params.source;
	render.border = m_params.border;
	render.offset = m_params.offset;
	m_registry.assign<decltype(render)>(imageEntity, std::move(render));

	return imageEntity;
}
