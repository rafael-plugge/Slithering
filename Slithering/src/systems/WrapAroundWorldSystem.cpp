#include "stdafx.h"
#include <src/systems/WrapAroundWorldSystem.h>

// Components
#include <src/components/Location.h>
#include <src/components/WrapAround.h>
#include <src/components/Dimension.h>

// Tags
#include <src/tags/World.h>

// Miscellaneous
#include <src/math/Rect.h>
#include <src/math/MathRect.h>

void app::sys::WrapAroundWorldSystem::init()
{
}

void app::sys::WrapAroundWorldSystem::update(app::time::seconds const & dt)
{
	auto const & world = m_registry.get<tags::World>();
	auto viewDimensions = m_registry.view<comp::WrapAround, comp::Location, comp::Dimension>();
	m_registry.view<comp::WrapAround, comp::Location>()
		.each([&, this](app::Entity const entity, comp::WrapAround const & wrapAround, comp::Location & location) -> void
	{
		if (viewDimensions.contains(entity))
		{
			auto & dimension = viewDimensions.get<comp::Dimension>(entity);
			auto const & entityBounds = math::Rectf{ location.position, dimension.size };

			if (auto const & result = math::isOutOfBounds(entityBounds, world.bounds); result.has_value())
			{
				app::Console::wrl("Collision occurred commencing wrap-around");

				bool const & isLeft = result->first.has_value() && !result->first.value();
				bool const & isRight = result->first.has_value() && result->first.value();
				bool const & isUp = result->second.has_value() && !result->second.value();
				bool const & isDown = result->second.has_value() && result->second.value();

				location.position.x += isLeft ? world.bounds.w
					: (isRight ? -world.bounds.w : 0.0f);
				location.position.y += isUp ? world.bounds.h
					: (isDown ? -world.bounds.h : 0.0f);
			}
		}
		else
		{

		}
	});
}
