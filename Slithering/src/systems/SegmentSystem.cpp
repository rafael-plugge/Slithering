#include "stdafx.h"
#include "SegmentSystem.h"
#include <src/math/Math.h>

void app::sys::SegmentSystem::init()
{
}

void app::sys::SegmentSystem::update(app::time::seconds const & dt)
{
	auto constexpr PLAYER_SPEED = 3.0f;
	auto view = m_registry.view<comp::Segment, comp::Motion, comp::Location>();
	auto const getSnakeSection = [&, this](app::Entity const & entity) -> SnakeSection const
	{
		auto [seg, mot, loc] = view.get<comp::Segment, comp::Motion, comp::Location>(entity);
		return std::move(SnakeSection{ seg, loc, mot });
	};
	view.each([&, this](app::Entity const entity, comp::Segment & segment, comp::Motion & motion, comp::Location & location)
	{
		if (!segment.parent.has_value() || !view.contains(*segment.parent)) { return; }
		// only process segments that aren't the head.

		SnakeSection const & parentSection = std::move(getSnakeSection(*segment.parent));
		math::Vector2f const & position = parentSection.location.position - location.position;
		std::float_t & direction = motion.direction.has_value()
			? *motion.direction
			: location.orientation;
		direction = math::toDegrees(std::atan2(-position.x, position.y)) + 90.0f;
		std::float_t const & distance = position.magnitude();
		std::float_t const & offset = segment.offset.magnitude();
		std::float_t const & distanceFactor = (distance / (offset == 0.0f ? 1.0f : offset));
		motion.speed = PLAYER_SPEED * distanceFactor;
	});
}
