#include "stdafx.h"
#include "GameFactory.h"
#include <src/utilities/Makers.h>
#include <src/input/Commands.h>

// factories
#include <src/factories/entities/ImageFactory.h>
#include <src/factories/entities/PlayerFactory.h>
#include <src/factories/entities/CameraFactory.h>
#include <src/factories/entities/SnakeFactory.h>
#include <src/factories/entities/FoodFactory.h>
#include <src/factories/entities/AiFactory.h>
#include <src/factories/entities/WorldFactory.h>

std::vector<app::Entity> app::fact::GameFactory::create()
{
	auto gameEntities = std::vector<app::Entity>();

	GameFactory::insertInto(gameEntities, this->createWorld());
	GameFactory::insertInto(gameEntities, this->createFood());
	GameFactory::insertInto(gameEntities, this->createSnake());
	GameFactory::insertInto(gameEntities, this->createPlayer());
	GameFactory::insertInto(gameEntities, this->createAi());
	GameFactory::insertInto(gameEntities, this->createCameras());

	return std::move(gameEntities);
}

std::vector<app::Entity> app::fact::GameFactory::createCameras()
{
	auto entities = std::vector<app::Entity>();
	auto params = par::fact::ent::CameraFactoryParameters();
	auto & entityParams = params.entityFactoryParams;
	auto cameraFactory = fact::ent::CameraFactory(params);

	{
		entityParams.entity = EntityFactory(entityParams).create();
		params.position = (math::Vector2f{ 1366.0f, 768.0f } / 2.0f);
		params.size = math::Vector2f{ 1366.0f, 768.0f };
		params.viewport = { 0.0f, 0.0f, 1.0f, 1.0f };
		params.target = m_cameraTarget;
		entities.push_back(cameraFactory.create());
	}
	{
		entityParams.entity.reset();
		params.position = { };
		params.size = math::Vector2f{ 2000, 2000 };
		params.viewport = { 0.0f, 0.0f, (300.0f / 1366.0f), (300.0f / 768.0f) };
		params.target.reset();
		entities.push_back(cameraFactory.create());
	}

	return std::move(entities);
}

std::vector<app::Entity> app::fact::GameFactory::createImages()
{
	auto entities = std::vector<app::Entity>();
	auto params = par::fact::ent::ImageFactoryParameters();
	auto imageFactory = fact::ent::ImageFactory(params);

	// Create image
	{
		params.position = { 100.0f, 100.0f };
		params.fill = sf::Color(0u, 255u, 255u, 255u);
		params.size = { 200.0f, 200.0f };
		params.origin = params.size / 2.0f;
		params.zIndex = 500u;
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

	{
		m_cameraTarget = EntityFactory(entityParams).create();
		{
			imageParams.position = { 500.0f, 500.0f };
			imageParams.size = { 100.0f, 100.0f };
			imageParams.origin = imageParams.size / 2.0f;
			imageParams.fill = sf::Color::Green;
			imageParams.zIndex = 3000u;
		}
		{
			snakeParams.amount = 3u;
			snakeParams.segmentFill = sf::Color::Green;
			snakeParams.bodyZIndex = 2900u;
			snakeParams.tailFill = sf::Color::Yellow;
			snakeParams.tailZIndex = 2800u;
			snakeParams.offset = { -55.0f, 0.0f };
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
	auto params = par::fact::ent::AiFactoryParameters();
	auto & snakeParams = params.snakeFactoryParams;
	auto & imageParams = snakeParams.imageFactoryParams;
	auto & entityParams = imageParams.entityFactoryParams;
	auto aiFactory = fact::ent::AiFactory(params);

	{
		{
			entityParams.entity = EntityFactory(entityParams).create();
		}
		{
			imageParams.position = { 500.0f, 500.0f };
			imageParams.size = { 100.0f, 100.0f };
			imageParams.origin = imageParams.size / 2.0f;
			imageParams.fill = sf::Color::Red;
			imageParams.zIndex = 1000u;
		}
		{
			snakeParams.amount = 3u;
			snakeParams.segmentFill = sf::Color::Red;
			snakeParams.bodyZIndex = 900u;
			snakeParams.tailFill = sf::Color::Yellow;
			snakeParams.tailZIndex = 800u;
			snakeParams.offset = { -55.0f, 0.0f };
			snakeParams.speed = 3.0f;
		}
		{
			params.aiCommands = {
				inp::AiCommand{ { }, inp::Command(std::in_place_type<com::DefaultCommand>) },
				inp::AiCommand{ { }, inp::Command(std::in_place_type<com::TurnLeftCommand>, entityParams.entity.value()) },
				inp::AiCommand{ { }, inp::Command(std::in_place_type<com::TurnRightCommand>, entityParams.entity.value()) }
			};
		}

		entities.emplace_back(aiFactory.create());
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

	{
		m_cameraTarget = entityParams.entity = EntityFactory(entityParams).create();
		imageParams.position = { 700.0f, 200.0f };
		imageParams.size = { 100.0f, 100.0f };
		imageParams.origin = imageParams.size / 2.0f;
		imageParams.fill = sf::Color::Blue;
		params.amount = 5u;
		params.segmentFill = sf::Color::Green;
		params.bodyZIndex = 900u;
		params.tailFill = sf::Color::Yellow;
		params.tailZIndex = 800u;
		params.offset = math::Vector2f{ 55.0f, 55.0f };
		params.speed = 0.0f;
		entities.push_back(snakeFactory.create());
	}

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
		auto const distanceFromCenter = 1000.0f;
		params.bounds = math::Rectf{ -distanceFromCenter, -distanceFromCenter, distanceFromCenter * 2.0f, distanceFromCenter * 2.0f };
		entities.push_back(worldFactory.create());
	}

	return std::move(entities);
}

void app::fact::GameFactory::insertInto(std::vector<app::Entity>& entities, std::vector<app::Entity> insert)
{
	entities.insert(entities.end()
		, std::make_move_iterator(insert.begin())
		, std::make_move_iterator(insert.end()));
}
