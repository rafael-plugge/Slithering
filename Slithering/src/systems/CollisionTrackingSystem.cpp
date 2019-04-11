#include "stdafx.h"
#include "CollisionTrackingSystem.h"

// components
#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Motion.h>
#include <src/components/Collision.h>

void app::sys::CollisionTrackingSystem::init()
{
	m_registry.prepare<comp::Location, comp::Dimension, comp::Collision, comp::Motion>();
	auto motionView = m_registry.view<comp::Location, comp::Dimension, comp::Collision, comp::Motion>(entt::persistent_t{});
	m_registry.view<comp::Location, comp::Dimension, comp::Collision>(entt::persistent_t{})
		.each([&, this](app::Entity const entity, comp::Location const & location, comp::Dimension const & dimension, comp::Collision & collision)
	{
		if (motionView.contains(entity)) { return; }

		collision.bounds = math::Rectf(location.position - dimension.origin, dimension.size);
	});
}

void app::sys::CollisionTrackingSystem::update(app::time::seconds const & dt)
{
	m_registry.view<comp::Location, comp::Dimension, comp::Collision, comp::Motion>(entt::persistent_t{})
		.each([&, this](app::Entity const entity, comp::Location const & location, comp::Dimension const & dimension, comp::Collision & collision, comp::Motion const & motion)
	{
		collision.bounds = std::move(math::Rectf(location.position - dimension.origin, dimension.size));
	});
}
