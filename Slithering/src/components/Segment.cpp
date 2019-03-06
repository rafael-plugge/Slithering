#include "stdafx.h"
#include "Segment.h"

void app::comp::Segment::apply(app::Registry & registry, app::Entity const entity, std::optional<app::Entity> parent, std::optional<app::Entity> child)
{
	auto segment = comp::Segment();
	segment.parent = parent;
	segment.child = child;
	registry.assign<decltype(segment)>(entity, std::move(segment));
}
