#include "stdafx.h"
#include "SnakeFactory.h"
#include <src/factories/entities/SegmentFactory.h>
// components
#include <src/components/Motion.h>
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
	auto & segmentImageParams = segmentFactoryParams.imageFactoryParams;
	auto & segmentEntityParams = segmentImageParams.entityFactoryParams;
	{
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
			segmentEntityParams.entity = segmentFactoryParams.tail;
			segmentImageParams.position += m_params.offset;
			segmentFactoryParams.head = m_entityParams.entity;
			segmentFactoryParams.tail = m_registry.create();
			segmentFactoryParams.offset += m_params.offset;
			auto entity = segmentFactory.create();
			if (!firstBody.has_value()) { firstBody = entity; }
		}
		// Head segment
		{
			comp::Motion::apply(m_registry, snakeHeadEntity);
			comp::Segment::apply(m_registry, snakeHeadEntity, std::nullopt, firstBody);
		}

		// Tail segment
		{
			segmentEntityParams.entity = segmentFactoryParams.tail;
			segmentImageParams.position += m_params.offset;
			segmentImageParams.fill = m_params.tailFill;
			segmentFactoryParams.head = m_entityParams.entity;
			segmentFactoryParams.tail.reset();
			segmentFactoryParams.offset += m_params.offset;
			segmentFactory.create();
		}
	}

	return snakeHeadEntity;
}
