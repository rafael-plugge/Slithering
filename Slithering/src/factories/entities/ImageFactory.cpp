#include "stdafx.h"
#include "ImageFactory.h"

// components
#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Layer.h>
#include <src/components/Render.h>

app::fact::ent::ImageFactory::ImageFactory(Parameters & params)
	: EntityFactory(params.entityFactoryParams)
	, m_params(params)
	, m_entityParams(params.entityFactoryParams)
{
}

app::Entity const app::fact::ent::ImageFactory::create()
{
	app::Entity const imageEntity = EntityFactory::create();

	comp::Location::apply(m_registry, imageEntity, m_params.position, m_params.orientation);
	comp::Dimension::apply(m_registry, imageEntity, m_params.size, m_params.origin);
	comp::Layer::apply(m_registry, imageEntity, m_params.zIndex);
	comp::Render::apply(m_registry, imageEntity, m_params.fill, m_params.source, m_params.border, m_params.offset);

	return imageEntity;
}
