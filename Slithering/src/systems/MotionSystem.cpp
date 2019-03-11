#include "stdafx.h"
#include "MotionSystem.h"
#include <src/math/Math.h>
// components
#include <src/components/Motion.h>
#include <src/components/Location.h>

void app::sys::MotionSystem::init()
{
}

void app::sys::MotionSystem::update(app::time::seconds const & dt)
{
	s_registry.view<comp::Motion, comp::Location>()
		.each([&dt](app::Entity const entity, comp::Motion & motion, comp::Location & location)
	{
		auto const & velocity = math::toVector(motion.direction.value_or(location.orientation)) * motion.speed;
		location.position += velocity;
	});
}
