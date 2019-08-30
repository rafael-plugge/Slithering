#include "stdafx.h"
#include <src/factories/entities/FsmFactory.h>

// components
#include <src/components/FiniteStateMachine.h>
#include <src/components/Collision.h>

app::fact::ent::FsmFactory::FsmFactory(Parameters& params)
	: SnakeFactory(params.snakeFactoryParams)
	, m_snakeParams(params.snakeFactoryParams)
	, m_params(params)
{
}

app::Entity const app::fact::ent::FsmFactory::create()
{
	app::Entity const entity = SnakeFactory::create();

	{
		m_registry.assign<comp::FiniteStateMachine>(entity);
	}
	{
		auto collision = comp::Collision();
		collision.bounds = math::Rectf();
		m_registry.assign<decltype(collision)>(entity, std::move(collision));
	}

	return entity;
}
