#include "stdafx.h"
#include "GameFactory.h"

// factories
#include <src/factories/entities/ImageFactory.h>
#include <src/factories/entities/PlayerFactory.h>
#include <src/factories/entities/CameraFactory.h>

std::vector<app::Entity> app::fact::GameFactory::create()
{
	auto gameEntities = std::vector<app::Entity>();

	GameFactory::insertInto(gameEntities, this->createCameras());
	GameFactory::insertInto(gameEntities, this->createImages());
	GameFactory::insertInto(gameEntities, this->createPlayer());

	return std::move(gameEntities);
}

std::vector<app::Entity> app::fact::GameFactory::createCameras()
{
	auto entities = std::vector<app::Entity>();
	auto params = par::fact::ent::CameraFactoryParameters();
	auto cameraFactory = fact::ent::CameraFactory(params);

	{
		params.position = (math::Vector2f{ 1366.0f, 768.0f } / 2.0f);
		params.size = math::Vector2f{ 1366.0f, 768.0f };
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
	auto playerFactory = fact::ent::PlayerFactory(params);

	{
		params.position = { 500.0f, 500.0f };
		params.zIndex = 1000u;
		entities.push_back(playerFactory.create());
	}

	return std::move(entities);
}

void app::fact::GameFactory::insertInto(std::vector<app::Entity>& entities, std::vector<app::Entity> insert)
{
	entities.insert(entities.end()
		, std::make_move_iterator(insert.begin())
		, std::make_move_iterator(insert.end()));
}
