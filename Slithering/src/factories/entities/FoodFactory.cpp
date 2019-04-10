#include "stdafx.h"
#include "FoodFactory.h"

// components
#include <src/components/Food.h>
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
		auto collision = comp::Collision();
		collision.bounds = math::Rectf(0.0f, 0.0f, 50.0f, 50.0f);
		m_registry.assign<decltype(collision)>(foodEntity, std::move(collision));
	}

	return foodEntity;
}
