#include "stdafx.h"
#include "SegmentSystem.h"
#include <src/math/Math.h>
// components
#include <src/components/Location.h>
#include <src/components/Motion.h>
#include <src/components/Segment.h>

void app::sys::SegmentSystem::init()
{
}

void app::sys::SegmentSystem::update(app::time::seconds const & dt)
{
	auto segmentView = m_registry.view<comp::Segment>();
	auto view = m_registry.view<comp::Segment, comp::Motion, comp::Location>();
	view.each([&, this](app::Entity const entity, comp::Segment & segment, comp::Motion & motion, comp::Location & location)
	{
		if (segment.child.has_value()) { return; }
		// will only process for snake tails

		auto segmentCounter = segmentView.get(segment.parent.value());
		auto segmentEntity = segment.parent.value();
	});
}
