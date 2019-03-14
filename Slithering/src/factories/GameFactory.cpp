#include "stdafx.h"
#include "GameFactory.h"
#include <src/utilities/Makers.h>
#include <src/input/Commands.h>

// factories
#include <src/factories/entities/ImageFactory.h>
#include <src/factories/entities/PlayerFactory.h>
#include <src/factories/entities/CameraFactory.h>
#include <src/factories/entities/SnakeFactory.h>

std::vector<app::Entity> app::fact::GameFactory::create()
{
	auto gameEntities = std::vector<app::Entity>();

	GameFactory::insertInto(gameEntities, this->createImages());
	GameFactory::insertInto(gameEntities, this->createSnake());
	GameFactory::insertInto(gameEntities, this->createPlayer());
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
		params.target = m_cameraTarget;
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
			imageParams.zIndex = 1000u;
		}
		{
			snakeParams.amount = 5u;
			snakeParams.segmentFill = sf::Color::Green;
			snakeParams.tailFill = sf::Color::Yellow;
			snakeParams.offset = { -55.0f, 0.0f };
		}
		{
			params.keyDowns = util::make_vector({
				  inp::KeyCommand{ { inp::KeyCode::Left, inp::KeyCode::A }, inp::Command(std::in_place_type<com::TurnLeftCommand>, entityParams.entity.value()) }
				, inp::KeyCommand{ { inp::KeyCode::Right, inp::KeyCode::D }, inp::Command(std::in_place_type<com::TurnRightCommand>, entityParams.entity.value()) }
			});
		}
		entities.push_back(playerFactory.create());
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
		params.tailFill = sf::Color::Yellow;
		params.offset = math::Vector2f{ 55.0f, 55.0f };
		entities.push_back(snakeFactory.create());
	}

	return std::move(entities);
}

void app::fact::GameFactory::insertInto(std::vector<app::Entity>& entities, std::vector<app::Entity> insert)
{
	entities.insert(entities.end()
		, std::make_move_iterator(insert.begin())
		, std::make_move_iterator(insert.end()));
}
