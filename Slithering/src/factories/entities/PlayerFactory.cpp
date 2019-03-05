#include "stdafx.h"
#include <src/factories/entities/PlayerFactory.h>
#include <src/utilities/Makers.h>

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
	using KeyCommand = comp::Input::KeyCommand;
	using MouseCommand = comp::Input::MouseCommand;
	using Command = comp::Input::Command;

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
	input.keyUpCommands.reserve(0);
	input.keyDownCommands = util::make_vector({
		  KeyCommand{ { Key::Left, Key::A }, Command(std::in_place_type<com::TurnLeftCommand>, playerEntity) }
		, KeyCommand{ { Key::Right, Key::D }, Command(std::in_place_type<com::TurnRightCommand>, playerEntity) }
	});
	input.keyPressedCommands.reserve(0);
	input.mouseDownCommands.reserve(0);
	input.mouseUpCommands.reserve(0);
	input.mousePressedCommands.reserve(0);
	m_registry.assign<decltype(input)>(playerEntity, std::move(input));

	auto motion = comp::Motion();
	motion.speed = 3.0f;
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
