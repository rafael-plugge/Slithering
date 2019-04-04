#include "stdafx.h"
#include <src/factories/entities/PlayerFactory.h>

// Components
#include <src/components/Input.h>
#include <src/components/Motion.h>
#include <src/components/Commandable.h>

// Tags
#include <src/tags/Player.h>

app::fact::ent::PlayerFactory::PlayerFactory(Parameters & params)
	: SnakeFactory(params.snakeFactoryParams)
	, m_params(params)
{
}

app::Entity const app::fact::ent::PlayerFactory::create()
{
	app::Entity const playerEntity = SnakeFactory::create();
	{
		auto input = comp::Input();
		input.keyUpCommands.insert(input.keyUpCommands.end()
			, m_params.keyUps.cbegin()
			, m_params.keyUps.cend());
		input.keyUpCommands.shrink_to_fit();
	
		input.keyDownCommands.insert(input.keyDownCommands.end()
			, m_params.keyDowns.cbegin()
			, m_params.keyDowns.cend());
		input.keyDownCommands.shrink_to_fit();

		input.keyPressedCommands.insert(input.keyPressedCommands.end()
			, m_params.keyPresses.cbegin()
			, m_params.keyPresses.cend());
		input.keyPressedCommands.shrink_to_fit();

		input.mouseDownCommands.insert(input.mouseDownCommands.end()
			, m_params.mouseDowns.cbegin()
			, m_params.mouseDowns.cend());
		input.mouseDownCommands.shrink_to_fit();

		input.mouseUpCommands.insert(input.mouseUpCommands.end()
			, m_params.mouseUps.cbegin()
			, m_params.mouseUps.cend());
		input.mouseUpCommands.shrink_to_fit();

		input.mousePressedCommands.insert(input.mousePressedCommands.end()
			, m_params.mousePresses.cbegin()
			, m_params.mousePresses.cend());
		input.mousePressedCommands.shrink_to_fit();

		m_registry.assign<decltype(input)>(playerEntity, std::move(input));
	}
	{
		auto & motion = m_registry.get<comp::Motion>(playerEntity);
		motion.speed = m_params.snakeFactoryParams.speed;
	}
	{
		auto player = tag::Player();
		m_registry.assign<decltype(player)>(entt::tag_t{}, playerEntity, std::move(player));
	}

	return playerEntity;
}
