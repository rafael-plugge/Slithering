#include "stdafx.h"
#include "GameFactory.h"

// factories
#include <src/factories/entities/ImageFactory.h>

std::vector<app::Entity> app::fact::GameFactory::create()
{
	auto gameEntities = std::vector<app::Entity>();

	GameFactory::insertInto(gameEntities, this->createImages());

	return std::move(gameEntities);
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
		entities.push_back(imageFactory.create());
	}

	return std::move(entities);
}

void app::fact::GameFactory::insertInto(std::vector<app::Entity>& entities, std::vector<app::Entity> insert)
{
	entities.insert(entities.end()
		, std::make_move_iterator(insert.begin())
		, std::make_move_iterator(insert.end()));
}
