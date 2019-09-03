#include "stdafx.h"
#include <src/factories/entities/TrainingFactory.h>

// components
#include <src/components/TrainingSet.h>

app::fact::ent::TrainingFactory::TrainingFactory(Parameters& params)
	: EntityFactory(params.entityFactoryParams)
	, m_params(params)
	, m_entityParams(params.entityFactoryParams)
{
}

app::Entity const app::fact::ent::TrainingFactory::create()
{
	app::Entity const trainingEntity = EntityFactory::create();

	{
		auto trainingSet = comp::TrainingSet();
		trainingSet.input.aiLocation = m_params.input.aiLocation;
		trainingSet.input.aiOrientation = m_params.input.aiOrientation;
		trainingSet.input.foodLocation = m_params.input.foodLocation;
		trainingSet.output.turnLeft = m_params.output.turnLeft;
		trainingSet.output.turnRight = m_params.output.turnRight;
		trainingSet.output.dontTurn = m_params.output.dontTurn;
		m_registry.assign<decltype(trainingSet)>(trainingEntity, std::move(trainingSet));
	}

	return trainingEntity;
}
