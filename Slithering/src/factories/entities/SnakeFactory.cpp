#include "stdafx.h"
#include "SnakeFactory.h"
#include <src/factories/entities/SegmentFactory.h>
#include <src/components/Segment.h>

app::fact::ent::SnakeFactory::SnakeFactory(SnakeFactory::Parameters & params)
	: ImageFactory(params.imageFactoryParams)
	, m_params(params)
	, m_imageParams(params.imageFactoryParams)
{
}

app::Entity const app::fact::ent::SnakeFactory::create()
{
	assert(m_entityParams.entity.has_value());
	auto segmentFactoryParams = par::fact::ent::SegmentFactoryParameters();
	{
		par::fact::ent::ImageFactoryParameters & segmentImageParams = segmentFactoryParams;
		segmentImageParams = m_imageParams;
		segmentImageParams.fill = m_params.segmentFill;
	}
	auto segmentFactory = fact::ent::SegmentFactory(segmentFactoryParams);

	app::Entity const snakeHeadEntity = ImageFactory::create();
	segmentFactoryParams.tail = m_registry.create();

	auto const AMOUNT = m_params.amount < 2u ? 0u : m_params.amount - 2u;
	if (AMOUNT > 0u)
	{
		auto firstBody = std::optional<app::Entity>();
		for (auto i = 0u; i < AMOUNT; ++i)
		{
			segmentFactoryParams.position += m_params.offset;
			segmentFactoryParams.head = m_entityParams.entity;
			segmentFactoryParams.entityFactoryParams.entity = segmentFactoryParams.tail;
			segmentFactoryParams.tail = m_registry.create();
			auto entity = segmentFactory.create();
			if (!firstBody.has_value()) { firstBody = entity; }
		}
		// Head segment
		{
			comp::Segment::apply(m_registry, snakeHeadEntity, std::nullopt, firstBody);
		}

		// Tail segment
		{
			segmentFactoryParams.position += m_params.offset;
			segmentFactoryParams.head = m_entityParams.entity;
			segmentFactoryParams.entityFactoryParams.entity = segmentFactoryParams.tail;
			segmentFactoryParams.tail.reset();
			segmentFactoryParams.fill = m_params.tailFill;
			segmentFactory.create();
		}
	}

	return snakeHeadEntity;
}
