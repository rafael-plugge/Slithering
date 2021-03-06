﻿#include "stdafx.h"
#include "SnakeFactory.h"
#include <src/factories/entities/SegmentFactory.h>
// components
#include <src/components/Motion.h>
#include <src/components/Commandable.h>
#include <src/components/Segment.h>
#include <src/components/WrapAround.h>

app::fact::ent::SnakeFactory::SnakeFactory(SnakeFactory::Parameters & params)
	: ImageFactory(params.imageFactoryParams)
	, m_params(params)
	, m_imageParams(params.imageFactoryParams)
{
}

app::Entity const app::fact::ent::SnakeFactory::create()
{
	constexpr std::size_t _Size = 4u;
	using iterator = std::array<std::size_t, _Size>::iterator;
	assert(m_entityParams.entity.has_value());
	auto segmentFactoryParams = par::fact::ent::SegmentFactoryParameters();
	auto & segmentImageParams = segmentFactoryParams.imageFactoryParams;
	auto & segmentEntityParams = segmentImageParams.entityFactoryParams;
	{
		segmentImageParams = m_imageParams;
		segmentImageParams.fill = m_params.segmentFill;
	}
	segmentFactoryParams.speed = m_params.speed;
	auto segmentFactory = fact::ent::SegmentFactory(segmentFactoryParams);

	app::Entity const snakeHeadEntity = ImageFactory::create();
	segmentFactoryParams.tail = m_registry.create();

	auto const AMOUNT = m_params.amount < 2u ? 0u : m_params.amount - 2u;
	if (AMOUNT > 0u)
	{
		auto firstBody = std::optional<app::Entity>();
		for (auto i = 0u; i < AMOUNT; ++i)
		{
			segmentFactoryParams.head = segmentEntityParams.entity;
			segmentEntityParams.entity = segmentFactoryParams.tail;
			segmentImageParams.position += m_params.offset;
			segmentImageParams.zIndex = m_params.bodyZIndex;
			segmentFactoryParams.tail = m_registry.create();
			segmentFactoryParams.offset = m_params.offset;
			auto entity = segmentFactory.create();
			if (!firstBody.has_value()) { firstBody = entity; }
		}
		// Head segment
		{
			{
				auto commandable = comp::Commandable();
				commandable.loop.push_back(inp::Command(std::in_place_type<com::ForwardCommand>, snakeHeadEntity));
				m_registry.assign<decltype(commandable)>(snakeHeadEntity, std::move(commandable));
			}
			comp::Motion::apply(m_registry, snakeHeadEntity, m_params.speed);
			comp::Segment::apply(m_registry, snakeHeadEntity, std::nullopt, firstBody);
			{
				auto wrapAround = comp::WrapAround();
				m_registry.assign<decltype(wrapAround)>(snakeHeadEntity, std::move(wrapAround));
			}
		}

		// Tail segment
		{
			segmentFactoryParams.head = segmentEntityParams.entity;
			segmentEntityParams.entity = segmentFactoryParams.tail;
			segmentImageParams.position += m_params.offset;
			segmentImageParams.fill = m_params.tailFill;
			segmentImageParams.zIndex = m_params.tailZIndex;
			segmentFactoryParams.tail.reset();
			segmentFactoryParams.offset = m_params.offset;
			segmentFactory.create();
		}
	}

	return snakeHeadEntity;
}
