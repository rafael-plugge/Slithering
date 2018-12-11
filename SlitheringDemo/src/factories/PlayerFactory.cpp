#include "stdafx.h"
#include <src/factories/PlayerFactory.h>

// Components
#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Render.h>
#include <src/components/Input.h>

// Tags
#include <src/tags/Player.h>

std::optional<app::Entity> app::fact::PlayerFactory::create()
{
	using Key = sf::Keyboard::Key;
	using Button = sf::Mouse::Button;

	app::Entity const entity = m_registry.create();

	auto location = comp::Location();
	location.position = { 10.0f, 10.0f };
	location.angle = 0.0f;
	m_registry.assign<decltype(location)>(entity, std::move(location));

	auto dimensions = comp::Dimension();
	dimensions.size = { 100.0f, 100.0f };
	dimensions.origin = {
		dimensions.size.x / 2.0f,
		dimensions.size.y / 2.0f
	};
	m_registry.assign<decltype(dimensions)>(entity, std::move(dimensions));

	auto input = comp::Input();
	input.keys = {
		std::make_pair(
			inp::Actions::MoveUp, comp::Input::MapKeysPressed{
				std::make_pair(Key::Up, false),
				std::make_pair(Key::W, false)
			}
		),
		std::make_pair(
			inp::Actions::MoveDown, comp::Input::MapKeysPressed{
				std::make_pair(Key::S, false),
				std::make_pair(Key::Down, false)
			}
		),
		std::make_pair(
			inp::Actions::MoveLeft, comp::Input::MapKeysPressed{
				std::make_pair(Key::A, false),
				std::make_pair(Key::Left, false)
			}
		),
		std::make_pair(
			inp::Actions::MoveRight, comp::Input::MapKeysPressed{
				std::make_pair(Key::D, false),
				std::make_pair(Key::Right, false)
			}
		)
	};
	input.buttons = {
		std::make_pair(
			inp::Actions::Stuff, comp::Input::MapButtonsPressed{
				std::make_pair(Button::Left, false),
				std::make_pair(Button::Right, false)
			}
		)
	};
	m_registry.assign<decltype(input)>(entity, std::move(input));

	auto render = comp::Render();
	render.fill = sf::Color(0u, 255u, 0u, 255u);
	m_registry.assign<decltype(render)>(entity, std::move(render));

	auto player = tag::Player();
	m_registry.assign<decltype(player)>(entt::tag_t{}, entity, std::move(player));

	return entity;
}
