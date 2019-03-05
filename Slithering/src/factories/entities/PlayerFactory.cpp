#include "stdafx.h"
#include <src/factories/entities/PlayerFactory.h>

// Components
#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Layer.h>
#include <src/components/Render.h>
#include <src/components/Input.h>
#include <src/components/Motion.h>

// Tags
#include <src/tags/Player.h>

app::fact::ent::PlayerFactory::PlayerFactory(Parameters const & params)
	: EntityFactory(params)
	, m_params(params)
{
}

app::Entity const app::fact::ent::PlayerFactory::create()
{
	using Key = sf::Keyboard::Key;
	using Button = sf::Mouse::Button;
	using Command = comp::Input::Command;
	constexpr auto MOVE_RIGHT = true;
	constexpr auto MOVE_LEFT = false;

	app::Entity const playerEntity = EntityFactory::create();

	auto location = comp::Location();
	location.position = m_params.position;
	location.orientation = 0.0f;
	m_registry.assign<decltype(location)>(playerEntity, std::move(location));

	auto dimensions = comp::Dimension();
	dimensions.size = { 100.0f, 100.0f };
	dimensions.origin = dimensions.size / 2.0f;
	m_registry.assign<decltype(dimensions)>(playerEntity, std::move(dimensions));

	auto input = comp::Input();
	input.keyUpCommands = {};
	input.keyDownCommands = {
		  std::make_pair(Key::Left, Command(std::in_place_type<com::MoveCommand>, playerEntity, MOVE_LEFT))
		, std::make_pair(Key::A, Command(std::in_place_type<com::MoveCommand>, playerEntity, MOVE_LEFT))
		, std::make_pair(Key::Right, Command(std::in_place_type<com::MoveCommand>, playerEntity, MOVE_RIGHT))
		, std::make_pair(Key::D, Command(std::in_place_type<com::MoveCommand>, playerEntity, MOVE_RIGHT))
	};
	input.keyPressedCommands = {};
	input.mouseDownCommands = {};
	input.mouseUpCommands = {};
	input.mousePressedCommands = {};
	m_registry.assign<decltype(input)>(playerEntity, std::move(input));

	auto motion = comp::Motion();
	motion.speed = 0.0f;
	m_registry.assign<decltype(motion)>(playerEntity, std::move(motion));

	auto layer = comp::Layer();
	layer.zIndex = m_params.zIndex;
	m_registry.assign<decltype(layer)>(playerEntity, std::move(layer));

	auto render = comp::Render();
	render.fill = sf::Color(0u, 255u, 0u, 255u);
	m_registry.assign<decltype(render)>(playerEntity, std::move(render));

	auto player = tag::Player();
	m_registry.assign<decltype(player)>(entt::tag_t{}, playerEntity, std::move(player));

	return playerEntity;
}
