#include "stdafx.h"
#include "FoodSystem.h"

#include <src/factories/entities/SegmentFactory.h>
#include <src/factories/GameFactory.h>
#include <src/utilities/Random.h>

// components
#include <src/components/Food.h>
#include <src/components/Collision.h>
#include <src/components/Segment.h>
#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Motion.h>
#include <src/components/Layer.h>
#include <src/components/Render.h>
#include <src/components/Destroy.h>
#include <src/components/FiniteStateMachine.h>
#include <src/components/NeuraNetwork.h>

// Contains implementation only free functions
namespace app::impl
{
	struct TailSection
	{
		app::Entity const entity;
		app::comp::Segment & segment;
	};
	TailSection findTail(app::Registry & registry, app::Entity const entity, app::comp::Segment & segment)
	{
		app::Entity child = segment.child.value_or(entity);
		for (; registry.get<app::comp::Segment>(child).child.has_value();
			child = registry.get<app::comp::Segment>(child).child.value());
		return TailSection{ child, registry.get<app::comp::Segment>(child) };
	}

	void createSegment(app::Registry & registry, TailSection tail)
	{
		auto segmentView = registry.view<comp::Location, comp::Dimension, comp::Motion, comp::Render, comp::Layer>();
		Entity const parentEntity = tail.segment.parent.value();
		comp::Segment & parent = registry.get<app::comp::Segment>(parentEntity);
		assert(segmentView.contains(parentEntity) && segmentView.contains(tail.entity));
		{
			auto [location, dimension, motion, render, layer] = segmentView.get<comp::Location, comp::Dimension, comp::Motion, comp::Render, comp::Layer>(parentEntity);
			auto const & [tailLocation, tailRender] = segmentView.get<comp::Location, comp::Render>(tail.entity);
			auto params = app::par::fact::ent::SegmentFactoryParameters();
			auto & imageParams = params.imageFactoryParams;
			auto & entityParams = imageParams.entityFactoryParams;
			auto factory = app::fact::ent::SegmentFactory(params);
			{
				entityParams.entity = app::fact::EntityFactory(entityParams).create();
			
				imageParams.fill = tailRender.fill;
				imageParams.border = render.border;
				imageParams.offset = render.offset;
				imageParams.source = render.source;
				imageParams.zIndex = layer.zIndex;
				
				imageParams.position = tailLocation.position;
				imageParams.orientation = tailLocation.orientation;

				imageParams.size = dimension.size;
				imageParams.origin = dimension.origin;

				params.head = parentEntity;
				parent.child = tail.segment.parent = entityParams.entity;
				params.tail = tail.entity;
				params.offset = tail.segment.offset;
				params.speed = motion.speed;
			}
			factory.create();
		}
	}
	void onFsmConsumption(app::Registry& registry, app::Entity const snakeEntity)
	{
		if (!registry.has<comp::FiniteStateMachine>(snakeEntity)) { return; }

		cout::wrl("FSM ate food");
		auto& fsm = registry.get<comp::FiniteStateMachine>(snakeEntity);
		fsm.nearestFood.reset();
	}
	void onNnConsumption(app::Registry& registry, app::Entity const snakeEntity)
	{
		if (!registry.has<comp::NeuralNetwork>(snakeEntity)) { return; }

		cout::wrl("NN ate food");
		auto& nn = registry.get<comp::NeuralNetwork>(snakeEntity);
		nn.neareastFood.reset();
	}
}

void app::sys::FoodSystem::init()
{
	m_foodDestroyed = false;
	m_registry.destruction<comp::Food>().connect<app::sys::FoodSystem, &app::sys::FoodSystem::onFoodDestruction>(this);
	{
		m_foodFactoryParams = par::fact::ent::FoodFactoryParameters();
		m_foodFactory.emplace(fact::ent::FoodFactory(m_foodFactoryParams));

		m_foodFactoryParams.imageFactoryParams.size = { 50.0f, 50.0f };
		m_foodFactoryParams.imageFactoryParams.origin = m_foodFactoryParams.imageFactoryParams.size / 2.0f;
		m_foodFactoryParams.imageFactoryParams.fill = sf::Color::Cyan;
		m_foodFactoryParams.imageFactoryParams.zIndex = 1000u;
	}
}

void app::sys::FoodSystem::update(app::time::seconds const & dt)
{
	m_registry.view<comp::Collision, comp::Food>()
		.each([&, this](app::Entity const foodEntity, comp::Collision const & collision, comp::Food const & food)
	{
		m_registry.view<comp::Segment, comp::Collision>()
			.each([&, this](app::Entity const snakeEntity, comp::Segment & segment, comp::Collision const & snakeCollision)
		{
			if (foodEntity == snakeEntity || segment.parent.has_value() ||
				!FoodSystem::check(collision.bounds, snakeCollision.bounds) || m_registry.has<comp::Destroy>(foodEntity)) { return; }

			impl::createSegment(m_registry, impl::findTail(m_registry, snakeEntity, segment));
			impl::onFsmConsumption(m_registry, snakeEntity);
			m_registry.assign<comp::Destroy>(foodEntity);
		});
	});

	if (m_foodDestroyed)
	{
		m_foodDestroyed = false;
		auto const spawnBounds = math::Rectf{ -500.0f, -500.0f, 1000.0f, 1000.0f };
		this->spawnFood(math::Vector2f{
			app::util::Random::gen(spawnBounds.x, spawnBounds.x + spawnBounds.w)
			, app::util::Random::gen(spawnBounds.y, spawnBounds.y + spawnBounds.h)
		});
	}
}

constexpr bool app::sys::FoodSystem::check(math::Rectf const & left, math::Rectf const & right)
{
	return left.x < (right.x + right.w) && (left.x + left.w) > right.x &&
		left.y < (right.y + right.h) && (left.y + left.h) > right.y;
}

void app::sys::FoodSystem::onFoodDestruction(app::Registry & registry, app::Entity const entity)
{
	this->m_foodDestroyed = true;
}

void app::sys::FoodSystem::spawnFood(math::Vector2f position)
{
	m_foodFactoryParams.imageFactoryParams.entityFactoryParams.entity.reset();
	m_foodFactoryParams.imageFactoryParams.position = std::move(position);
	m_foodFactory->create();
}
