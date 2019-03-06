#include "stdafx.h"
#include "Layer.h"

void app::comp::Layer::apply(app::Registry & registry, app::Entity const entity, std::uint16_t zIndex)
{
	auto layer = comp::Layer();
	layer.zIndex = std::move(zIndex);
	registry.assign<decltype(layer)>(entity, std::move(layer));
}
