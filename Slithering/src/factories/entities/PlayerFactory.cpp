#include "stdafx.h"
#include <src/factories/entities/PlayerFactory.h>

// Components
#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Render.h>
#include <src/components/Input.h>

// Tags
#include <src/tags/Player.h>

app::fact::PlayerFactory::PlayerFactory(Parameters const & params)
	: EntityFactory(params)
	, m_params(params)
{
}

app::Entity const app::fact::PlayerFactory::create()
{
	using Key = sf::Keyboard::Key;
	using Button = sf::Mouse::Button;

	app::Entity const playerEntity = EntityFactory::create();

	auto location = comp::Location();
	location.position = m_params.position;
	location.orientation = 0.0f;
	m_registry.assign<decltype(location)>(playerEntity, std::move(location));

	auto dimensions = comp::Dimension();
	dimensions.size = { 100.0f, 100.0f };
	dimensions.origin = {
		dimensions.size.x / 2.0f,
		dimensions.size.y / 2.0f
	};
	m_registry.assign<decltype(dimensions)>(playerEntity, std::move(dimensions));

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
	m_registry.assign<decltype(input)>(playerEntity, std::move(input));

	auto render = comp::Render();
	render.fill = sf::Color(0u, 255u, 0u, 255u);
	m_registry.assign<decltype(render)>(playerEntity, std::move(render));

	auto player = tag::Player();
	m_registry.assign<decltype(player)>(entt::tag_t{}, playerEntity, std::move(player));

	return playerEntity;
}
