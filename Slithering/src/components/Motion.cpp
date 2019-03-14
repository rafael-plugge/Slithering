#include "stdafx.h"
#include "Motion.h"

void app::comp::Motion::apply(app::Registry & registry, app::Entity const entity, std::float_t speed, std::optional<std::float_t> direction)
{
	registry.assign<comp::Motion>(entity, std::move(comp::Motion{ speed, direction }));
}
