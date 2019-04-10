#include "stdafx.h"
#include <src/components/Dimension.h>

void app::comp::Dimension::apply(app::Registry & registry, app::Entity const entity, math::Vector2f size, std::optional<math::Vector2f> origin)
{
	auto dimension = comp::Dimension();
	dimension.size = std::move(size);
	dimension.origin = origin.value_or(dimension.size / 2.0f);
	registry.assign<decltype(dimension)>(entity, std::move(dimension));
}
