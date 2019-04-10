#include "stdafx.h"
#include <src/components/Render.h>

void app::comp::Render::apply(app::Registry & registry, app::Entity const entity, std::variant<std::shared_ptr<sf::Texture>, sf::Color> fill, std::optional<sf::IntRect> source, math::Vector2f border, math::Vector2f offset)
{
	auto render = comp::Render();
	render.fill = std::move(fill);
	render.source = std::move(source);
	render.offset = std::move(offset);
	render.border = std::move(border);
	registry.assign<decltype(render)>(entity, std::move(render));
}
