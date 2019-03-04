#include "stdafx.h"
#include "GameFactory.h"

// factories
#include <src/factories/entities/ImageFactory.h>

std::vector<app::Entity> app::fact::GameFactory::create()
{
	auto gameEntities = std::vector<app::Entity>();

	auto imageFactoryParams = par::fact::ent::ImageFactoryParameters();
	auto imageFactory = fact::ent::ImageFactory(imageFactoryParams);

	// Create image
	{
		imageFactoryParams.position = { 100.0f, 100.0f };
		gameEntities.push_back(imageFactory.create());
	}

	return std::move(gameEntities);
}
