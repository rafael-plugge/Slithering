#include "stdafx.h"
#include "SegmentFactory.h"
#include <src/factories/entities/ImageFactory.h>

#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Segment.h>
#include <src/components/Layer.h>
#include <src/components/Render.h>

app::fact::ent::SegmentFactory::SegmentFactory(Parameters & params)
	: ImageFactory(params)
	, m_params(params)
{
}

app::Entity const app::fact::ent::SegmentFactory::create()
{
	app::Entity const segmentEntity = ImageFactory::create();

	comp::Segment::apply(m_registry, segmentEntity
		, m_params.head
		, m_params.tail
	);

	return segmentEntity;
}
