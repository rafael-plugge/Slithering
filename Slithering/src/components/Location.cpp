#include "stdafx.h"
#include <src/components/Location.h>

void app::comp::Location::apply(app::Registry & registry, app::Entity const entity, math::Vector2f position, std::float_t orientation)
{
	auto location = comp::Location{
		  std::move(position)
		, std::move(orientation)
	};
	registry.assign<decltype(location)>(entity, std::move(location));
}
