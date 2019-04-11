#include "stdafx.h"
#include "FoodFactory.h"

// components
#include <src/components/Food.h>
#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Collision.h>

app::fact::ent::FoodFactory::FoodFactory(Parameters & params)
	: ImageFactory(params.imageFactoryParams)
	, m_imageParams(params.imageFactoryParams)
	, m_params(params)
{
}

app::Entity const app::fact::ent::FoodFactory::create()
{
	app::Entity const foodEntity = ImageFactory::create();
	
	{
		auto food = comp::Food();
		m_registry.assign<decltype(food)>(foodEntity, std::move(food));
	}
	{
		auto & location = m_registry.get<comp::Location>(foodEntity);
		auto & dimension = m_registry.get<comp::Dimension>(foodEntity);
		auto collision = comp::Collision();
		collision.bounds = math::Rectf(location.position - dimension.origin, dimension.size);
		m_registry.assign<decltype(collision)>(foodEntity, std::move(collision));
	}

	return foodEntity;
}
