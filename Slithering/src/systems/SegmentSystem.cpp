#include "stdafx.h"
#include "SegmentSystem.h"
#include <src/math/Math.h>

void app::sys::SegmentSystem::init()
{
}

void app::sys::SegmentSystem::update(app::time::seconds const & dt)
{
	auto segmentView = m_registry.view<comp::Segment>();
	auto view = m_registry.view<comp::Segment, comp::Motion, comp::Location>();
	auto const getSnakeSection = [&, this](app::Entity const & entity) -> SnakeSection
	{
		auto [seg, mot, loc] = view.get<comp::Segment, comp::Motion, comp::Location>(entity);
		return SnakeSection{ seg, loc, mot };
	};
	view.each([&, this](app::Entity const entity, comp::Segment & segment, comp::Motion & motion, comp::Location & location)
	{
		if (segment.parent.has_value()) { return; }
		// will only process for snake heads

		for (app::Entity childEntity = entity; ; childEntity = segmentView.get(childEntity).child.value())
		{
			//if (!view.contains(childEntity)) { continue; }
			SnakeSection childSection = std::move(getSnakeSection(childEntity));

			if (!childSection.segment.parent.has_value() || !view.contains(childSection.segment.parent.value())) { continue; }
			SnakeSection parentSection = std::move(getSnakeSection(childSection.segment.parent.value()));

			std::float_t & direction = childSection.motion.direction.has_value()
				? childSection.motion.direction.value()
				: childSection.location.orientation;

			auto const & position = parentSection.location.position - childSection.location.position;
			direction = app::math::toDegrees(std::atan2(-position.x, position.y)) + 90;
			if (segmentView.get(childEntity).child.has_value()) { break; }
		}
	});
}
