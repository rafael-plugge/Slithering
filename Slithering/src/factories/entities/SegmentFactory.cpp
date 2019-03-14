#include "stdafx.h"
#include "SegmentFactory.h"
#include <src/factories/entities/ImageFactory.h>
// components
#include <src/components/Motion.h>
#include <src/components/Segment.h>

app::fact::ent::SegmentFactory::SegmentFactory(Parameters & params)
	: ImageFactory(params.imageFactoryParams)
	, m_params(params)
{
}

app::Entity const app::fact::ent::SegmentFactory::create()
{
	app::Entity const segmentEntity = ImageFactory::create();

	{
		auto motion = comp::Motion();
		motion.speed = 0.0f;
		m_registry.assign<decltype(motion)>(segmentEntity, std::move(motion));
	}

	comp::Segment::apply(m_registry, segmentEntity
		, m_params.head
		, m_params.tail
		, m_params.offset
	);

	return segmentEntity;
}
