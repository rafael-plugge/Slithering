#include "stdafx.h"
#include "CameraTrackingSystem.h"
#include <src/components/Camera.h>
#include <src/components/Location.h>

void app::sys::CameraTrackingSystem::init()
{
}

void app::sys::CameraTrackingSystem::update(app::time::seconds const & dt)
{
	auto const locationView = s_registry.view<comp::Location>();
	s_registry.view<comp::Location, comp::Camera>()
		.each([&, this](app::Entity const & entity, comp::Location & location, comp::Camera & camera) -> void
	{
		if (!camera.target.has_value() || !locationView.contains(camera.target.value())) { return; }

		auto const & targetLocation = locationView.get(camera.target.value());
		location.position = targetLocation.position;
	});
}
