#include "stdafx.h"
#include "FoodSystem.h"

// components
#include <src/components/Food.h>
#include <src/components/Collision.h>
#include <src/components/Segment.h>

void app::sys::FoodSystem::init()
{
}

void app::sys::FoodSystem::update(app::time::seconds const & dt)
{
	m_registry.view<comp::Collision, comp::Food>()
		.each([&, this](app::Entity const foodEntity, comp::Collision const & collision, comp::Food const & food)
	{
		m_registry.view<comp::Segment, comp::Collision>()
			.each([&, this](app::Entity const snakeEntity, comp::Segment const & segment, comp::Collision const & snakeCollision)
		{
			if (foodEntity == snakeEntity || segment.parent.has_value() ||
				!FoodSystem::check(collision.bounds, snakeCollision.bounds)) { return; }

			app::cout::wrl("Collision occurred!");
		});
	});
}

/*
if (RectA.X1 < RectB.X2 && RectA.X2 > RectB.X1 &&
	RectA.Y1 > RectB.Y2 && RectA.Y2 < RectB.Y1)
*/

constexpr bool app::sys::FoodSystem::check(math::Rectf const & left, math::Rectf const & right)
{
	return left.x < (right.x + right.w) && (left.x + left.w) > right.x &&
		left.y < (right.y + right.h) && (left.y + left.h) > right.y;
}
