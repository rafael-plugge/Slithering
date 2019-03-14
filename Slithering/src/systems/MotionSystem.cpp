#include "stdafx.h"
#include "MotionSystem.h"
#include <src/math/Math.h>
// components
#include <src/components/Motion.h>
#include <src/components/Location.h>
#include <src/components/Segment.h>

void app::sys::MotionSystem::init()
{
}

void app::sys::MotionSystem::update(app::time::seconds const & dt)
{
	auto segmentView = m_registry.view<comp::Segment, comp::Motion, comp::Location>();
	m_registry.view<comp::Motion, comp::Location>()
		.each([&, this](app::Entity const entity, comp::Motion & motion, comp::Location & location)
	{
		if (segmentView.contains(entity) && segmentView.get<comp::Segment>(entity).parent.has_value()) { return; }
		auto const & velocity = math::toVector(motion.direction.value_or(location.orientation)) * motion.speed;
		location.position += velocity;
	});
}
