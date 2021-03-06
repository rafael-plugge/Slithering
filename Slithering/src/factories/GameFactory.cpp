﻿#include "stdafx.h"
#include "GameFactory.h"
#include <src/utilities/Makers.h>
#include <src/input/Commands.h>
#include <src/singletons/SettingsSingleton.h>
#include <src/math/Math.h>

// factories
#include <src/factories/entities/ImageFactory.h>
#include <src/factories/entities/PlayerFactory.h>
#include <src/factories/entities/CameraFactory.h>
#include <src/factories/entities/SnakeFactory.h>
#include <src/factories/entities/FoodFactory.h>
#include <src/factories/entities/AiFactory.h>
#include <src/factories/entities/WorldFactory.h>
#include <src/factories/entities/FsmFactory.h>
#include <src/factories/entities/TrainingFactory.h>

std::vector<app::Entity> app::fact::GameFactory::create()
{
	auto gameEntities = std::vector<app::Entity>();

	auto const& settings = app::sin::Settings::get();
	if (settings.ai.train)
	{
		GameFactory::insertInto(gameEntities, this->createWorld());
		GameFactory::insertInto(gameEntities, this->createImages());
		GameFactory::insertInto(gameEntities, this->createFood());
		GameFactory::insertInto(gameEntities, this->createAi());
		GameFactory::insertInto(gameEntities, this->createTrainingData());
		GameFactory::insertInto(gameEntities, this->createCameras());
	}
	else
	{
		GameFactory::insertInto(gameEntities, this->createWorld());
		GameFactory::insertInto(gameEntities, this->createImages());
		GameFactory::insertInto(gameEntities, this->createFood());
		GameFactory::insertInto(gameEntities, this->createSnake());
		GameFactory::insertInto(gameEntities, this->createPlayer());
		GameFactory::insertInto(gameEntities, this->createAi());
		GameFactory::insertInto(gameEntities, this->createFsm());
		GameFactory::insertInto(gameEntities, this->createCameras());
	}


	return std::move(gameEntities);
}

std::vector<app::Entity> app::fact::GameFactory::createCameras()
{
	auto entities = std::vector<app::Entity>();
	auto params = par::fact::ent::CameraFactoryParameters();
	auto & entityParams = params.entityFactoryParams;
	auto cameraFactory = fact::ent::CameraFactory(params);

	if (app::sin::Settings::get().playerEnabled)
	{
		{
			entityParams.entity = EntityFactory(entityParams).create();
			params.position = (math::Vector2f{ 1366.0f, 768.0f } / 2.0f);
			params.size = math::Vector2f{ 1366.0f, 768.0f };
			params.viewport = { 0.0f, 0.0f, 1.0f, 1.0f };
			params.target = m_cameraTarget;
			params.baseIndex = 0u;
			entities.push_back(cameraFactory.create());
		}
		{
			entityParams.entity.reset();
			params.position = { };
			params.size = math::Vector2f{ 2000, 2000 };
			params.viewport = { 0.0f, 0.0f, (300.0f / 1366.0f), (300.0f / 768.0f) };
			params.baseIndex = 1u;
			params.target.reset();
			entities.push_back(cameraFactory.create());
		}
	}
	else // Player is disabled therefore make one camera centered on middle of map.
	{
		auto const ratio = math::Vector2f{ 2000.0f, 2000.0f } / math::Vector2f{ 1366.0f, 768.0f };
		{
			entityParams.entity.reset();
			entityParams.entity = EntityFactory(entityParams).create();
			params.size = math::Vector2f{ 1366.0f, 768.0f } * 2.7f;
			params.position = { 0.0f, 0.0f };
			params.viewport = { 0.0f, 0.0f, 1.0f, 1.0f };
			params.target.reset();
			params.baseIndex = 0u;
			entities.push_back(cameraFactory.create());
		}
	}


	return std::move(entities);
}

std::vector<app::Entity> app::fact::GameFactory::createImages()
{
	auto entities = std::vector<app::Entity>();
	auto params = par::fact::ent::ImageFactoryParameters();
	auto imageFactory = fact::ent::ImageFactory(params);

	// Black background
	{
		params.entityFactoryParams.entity.reset();
		params.position = { 0.0f, 0.0f };
		params.fill = sf::Color::Black;
		params.size = { 2000.0f, 2000.0f };
		params.origin = params.size / 2.0f;
		params.zIndex = 0u;
		entities.push_back(imageFactory.create());
	}

	return std::move(entities);
}

std::vector<app::Entity> app::fact::GameFactory::createPlayer()
{
	auto entities = std::vector<app::Entity>();
	auto params = par::fact::ent::PlayerFactoryParameters();
	auto & snakeParams = params.snakeFactoryParams;
	auto & imageParams = snakeParams.imageFactoryParams;
	auto & entityParams = imageParams.entityFactoryParams;
	auto playerFactory = fact::ent::PlayerFactory(params);

	if (app::sin::Settings::get().playerEnabled) // Player is enabled
	{
		m_cameraTarget = EntityFactory(entityParams).create();
		{
			imageParams.position = { 500.0f, 500.0f };
			imageParams.size = { 40.0f, 40.0f };
			imageParams.origin = imageParams.size / 2.0f;
			imageParams.fill = sf::Color::Green;
			imageParams.zIndex = 3000u;
		}
		{
			snakeParams.amount = 3u;
			snakeParams.segmentFill = sf::Color::Green;
			snakeParams.bodyZIndex = 2900u;
			snakeParams.tailFill = sf::Color::Green;
			snakeParams.tailZIndex = 2800u;
			snakeParams.offset = { -25.0f, 0.0f };
			snakeParams.speed = 3.0f;
		}
		{
			params.keyDowns = util::make_vector({
				  inp::KeyCommand{ { inp::KeyCode::Left, inp::KeyCode::A }, inp::Command(std::in_place_type<com::TurnLeftCommand>, entityParams.entity.value()) }
				, inp::KeyCommand{ { inp::KeyCode::Right, inp::KeyCode::D }, inp::Command(std::in_place_type<com::TurnRightCommand>, entityParams.entity.value()) }
				, inp::KeyCommand{ { inp::KeyCode::R }, inp::Command(std::in_place_type<com::ResetCommand>, entityParams.entity.value(), imageParams.position) }
			});
			params.keyPresses = util::make_vector({
				  inp::KeyCommand{ { inp::KeyCode::Up, inp::KeyCode::W }, inp::Command(std::in_place_type<com::SpeedCommand>, entityParams.entity.value(), snakeParams.speed) }
				, inp::KeyCommand{ { inp::KeyCode::Down, inp::KeyCode::S }, inp::Command(std::in_place_type<com::SpeedCommand>, entityParams.entity.value(), -snakeParams.speed) }
			});
		}
		entities.push_back(playerFactory.create());
	}

	return std::move(entities);
}

std::vector<app::Entity> app::fact::GameFactory::createAi()
{
	auto entities = std::vector<app::Entity>();
	if (auto const& settings = app::sin::Settings::get(); !settings.ai.enabled) { return std::move(entities); }

	auto params = par::fact::ent::AiFactoryParameters();
	auto & snakeParams = params.snakeFactoryParams;
	auto & imageParams = snakeParams.imageFactoryParams;
	auto & entityParams = imageParams.entityFactoryParams;
	auto aiFactory = fact::ent::AiFactory(params);

	if (auto const & settings = app::sin::Settings::get(); settings.ai.enabled)
	{
		{
			entityParams.entity = EntityFactory(entityParams).create();
		}
		{
			imageParams.position = { 500.0f, 500.0f };
			imageParams.size = { 40.0f, 40.0f };
			imageParams.origin = imageParams.size / 2.0f;
			imageParams.fill = sf::Color::Yellow;
			imageParams.zIndex = 1000u;
			imageParams.orientation = 90.0f;
		}
		{
			snakeParams.amount = 3u;
			snakeParams.segmentFill = sf::Color::Yellow;
			snakeParams.bodyZIndex = 900u;
			snakeParams.tailFill = sf::Color::Yellow;
			snakeParams.tailZIndex = 800u;
			snakeParams.offset = { 25.0f, 0.0f };
			snakeParams.speed = -2.0f;
		}
		{
			params.commands = {
				inp::Command(std::in_place_type<com::TurnLeftCommand>, entityParams.entity.value()),
				inp::Command(std::in_place_type<com::TurnRightCommand>, entityParams.entity.value()),
				inp::Command(std::in_place_type<com::DefaultCommand>)
			};
		}

		entities.emplace_back(aiFactory.create());
	}

	return std::move(entities);
}

std::vector<app::Entity> app::fact::GameFactory::createFsm()
{
	auto entities = std::vector<app::Entity>();
	if (auto const& settings = app::sin::Settings::get(); !settings.fsmEnabled) { return std::move(entities); }

	auto params = par::fact::ent::FsmFactoryParameters();
	auto& snakeParams = params.snakeFactoryParams;
	auto& imageParams = snakeParams.imageFactoryParams;
	auto& entityParams = imageParams.entityFactoryParams;
	auto fsmFactory = fact::ent::FsmFactory(params);

	{
		{
			entityParams.entity = EntityFactory(entityParams).create();
		}
		{
			imageParams.position = { -2000.0f, 2000.0f };
			imageParams.size = { 40.0f, 40.0f };
			imageParams.origin = imageParams.size / 2.0f;
			imageParams.fill = sf::Color::Magenta;
			imageParams.zIndex = 1010u;
		}
		{
			snakeParams.amount = 3u;
			snakeParams.segmentFill = sf::Color::Magenta;
			snakeParams.bodyZIndex = 910u;
			snakeParams.tailFill = sf::Color::Magenta;
			snakeParams.tailZIndex = 810u;
			snakeParams.offset = { -25.0f, 0.0f };
			snakeParams.speed = 2.0f;
		}

		entities.emplace_back(fsmFactory.create());
	}

	return std::move(entities);
}

std::vector<app::Entity> app::fact::GameFactory::createSnake()
{
	auto entities = std::vector<app::Entity>();
	auto params = par::fact::ent::SnakeFactoryParameters();
	auto & imageParams = params.imageFactoryParams;
	auto & entityParams = imageParams.entityFactoryParams;
	auto snakeFactory = fact::ent::SnakeFactory(params);

	imageParams.size = { 40.0f, 40.0f };
	imageParams.origin = imageParams.size / 2.0f;
	imageParams.fill = sf::Color::White;
	params.segmentFill = sf::Color::White;
	params.tailFill = sf::Color::White;
	params.amount = 5u;
	params.bodyZIndex = 900u;
	params.tailZIndex = 800u;
	params.offset = math::Vector2f{ -25.0f, 0.0f };
	params.speed = 1.0f;
	auto const& spawnSnake = [&](math::Vector2f const& pos, float const& orientation, sf::Color const& fill)
	{
		imageParams.fill = fill;
		params.segmentFill = fill;
		params.tailFill = fill;
		entityParams.entity = EntityFactory(entityParams).create();
		imageParams.position = pos;
		imageParams.orientation = orientation;
		entities.push_back(snakeFactory.create());
		entityParams.entity.reset();
	};
	spawnSnake({ 950.0f, 950.0f }, 90.0f,	sf::Color::White);
	spawnSnake({ -950.0f, -950.0f }, 0.0f,	sf::Color::White);
	spawnSnake({ 950.0f, 950.0f }, 180.0f,	sf::Color::White);
	spawnSnake({ -950.0f, -950.0f }, -90.0f,sf::Color::White);

	return std::move(entities);
}

std::vector<app::Entity> app::fact::GameFactory::createFood()
{
	auto entities = std::vector<app::Entity>();
	auto params = par::fact::ent::FoodFactoryParameters();
	auto & imageParams = params.imageFactoryParams;
	auto & entityParams = imageParams.entityFactoryParams;
	auto foodFactory = fact::ent::FoodFactory(params);

	{
		imageParams.size = { 50.0f, 50.0f };
		imageParams.origin = imageParams.size / 2.0f;
		imageParams.fill = sf::Color::Cyan;
		imageParams.zIndex = 1000u;
		auto const spawnFood = [&](math::Vector2f const & position)
		{
			entityParams.entity.reset();
			imageParams.position = position;
			entities.emplace_back(foodFactory.create());
		};
		spawnFood({ 200.0f, 200.0f });
		spawnFood({ 300.0f, 200.0f });
		spawnFood({ 100.0f, 100.0f });
		spawnFood({ -100.0f, 100.0f });
		spawnFood({ 100.0f, -100.0f });
		spawnFood({ 500.0f, -400.0f });
	}

	return std::move(entities);
}

std::vector<app::Entity> app::fact::GameFactory::createWorld()
{
	auto entities = std::vector<app::Entity>();
	auto params = par::fact::ent::WorldFactoryParams();
	auto & entityParams = params.entityFactoryParams;
	auto worldFactory = fact::ent::WorldFactory(params);

	{
		{
			auto & borderParams = params.borderFactoryParams;
			auto & borderImageParams = borderParams.imageFactoryParams;

			borderParams.thickness = 10.0f;
			borderImageParams.fill = sf::Color::White;
			borderImageParams.orientation = 0.0f;
			borderImageParams.zIndex = 500u;
		}

		auto const distanceFromCenter = 1000.0f;
		params.bounds = math::Rectf{ -distanceFromCenter, -distanceFromCenter, distanceFromCenter * 2.0f, distanceFromCenter * 2.0f };
		entities.push_back(worldFactory.create());
	}

	return std::move(entities);
}

std::vector<app::Entity> app::fact::GameFactory::createTrainingData()
{
	auto entities = std::vector<app::Entity>();
	if (auto const& settings = app::sin::Settings::get(); !settings.ai.train) { return std::move(entities); }
	
	// Was removed due to slow data generation and
	// limited how many training scenarios we could test because of excessive memory usage.

	return std::move(entities);
}

void app::fact::GameFactory::insertInto(std::vector<app::Entity>& entities, std::vector<app::Entity> insert)
{
	entities.insert(entities.end()
		, std::make_move_iterator(insert.begin())
		, std::make_move_iterator(insert.end()));
}
