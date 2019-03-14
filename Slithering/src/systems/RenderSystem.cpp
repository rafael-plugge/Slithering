#include "stdafx.h"
#include <src/systems/RenderSystem.h>
#include <src/utilities/Variant.h>

// components
#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Render.h>
#include <src/components/Layer.h>
#include <src/components/Camera.h>

app::sys::RenderSystem::RenderSystem(bool & running)
	: BaseSystem()
	, m_running(running)
	, m_renderShape()
	, m_contextSettings(
		  Default::ContextSettings::DEPTH_BUFFER_BITS, Default::ContextSettings::STENCIL_BUFFER_BITS, Default::ContextSettings::ANTIALIASING
		, Default::ContextSettings::MAJOR_VERSION, Default::ContextSettings::MINOR_VERSION, Default::ContextSettings::ATTRIBUTE, Default::ContextSettings::SRGB_CAPABLE)
	, m_window(
		  sf::VideoMode(Default::Window::VideoMode::WIDTH, Default::Window::VideoMode::HEIGHT, Default::Window::VideoMode::BITS_PER_PIXEL)
		, Default::Window::TITLE, Default::Window::STYLE, m_contextSettings)
	, m_event()
	, m_view()
{
}

app::sys::RenderSystem::~RenderSystem()
{
	if (m_window.isOpen()) { m_window.close(); }
}

void app::sys::RenderSystem::pollEvents(app::inp::KeyHandler & keyHandler, app::inp::MouseHandler & mouseHandler)
{
	using EventType = sf::Event::EventType;
	while (m_window.pollEvent(m_event))
	{
		switch (m_event.type)
		{
			case EventType::Closed:
				m_window.close();
				m_running = false;
				break;
			case EventType::KeyPressed:
				keyHandler.updateKey(m_event.key.code, true);
				break;
			case EventType::KeyReleased:
				keyHandler.updateKey(m_event.key.code, false);
				break;
			case EventType::MouseMoved:
				mouseHandler.updatePosition(m_event.mouseMove.x, m_event.mouseMove.y);
				break;
			case EventType::MouseButtonPressed:
				mouseHandler.updateButton(m_event.mouseButton.button, true);
				break;
			case EventType::MouseButtonReleased:
				mouseHandler.updateButton(m_event.mouseButton.button, false);
				break;
			default:
				break;
		}
	}
}

void app::sys::RenderSystem::init()
{
	m_registry.construction<comp::Layer>().connect<&app::sys::RenderSystem::sortLayers>();
	m_registry.destruction<comp::Layer>().connect<&app::sys::RenderSystem::sortLayers>();
	sys::RenderSystem::sortLayers(m_registry, 0u);
}

void app::sys::RenderSystem::update(app::time::seconds const & dt)
{
	m_window.clear(sf::Color::Black);
	auto const & renderView = m_registry.view<comp::Layer, comp::Location, comp::Dimension, comp::Render>(entt::persistent_t());
	m_registry.view<comp::Camera, comp::Location, comp::Dimension>()
		.each([&, this](app::Entity const cameraEntity, comp::Camera const & camera, comp::Location const & cameraLocation, comp::Dimension const & cameraDimension)
	{
		m_view.setCenter(cameraLocation.position.x, cameraLocation.position.y);
		m_view.setRotation(cameraLocation.orientation);
		m_view.setSize(cameraDimension.size.x, cameraDimension.size.y);
		m_window.setView(m_view);
		m_registry.view<comp::Layer>()
			.each([&, this](app::Entity const entity, comp::Layer const & layer)
		{
			auto const &[location, dimension, render] = renderView.get<comp::Location, comp::Dimension, comp::Render>(entity);

			m_renderShape.setPosition(location.position.x, location.position.y);
			m_renderShape.setRotation(location.orientation);
			m_renderShape.setFillColor(sf::Color::White);
			m_renderShape.setTexture(nullptr, true);
			std::visit(util::overload{
				  [&](std::shared_ptr<sf::Texture> const & texture) { m_renderShape.setTexture(texture.get(), true); }
				, [&](sf::Color const & color) { m_renderShape.setFillColor(color); }
			}, render.fill);
			m_renderShape.setSize({ dimension.size.x, dimension.size.y });
			m_renderShape.setOrigin(dimension.origin.x, dimension.origin.y);
			m_window.draw(m_renderShape);
		});
	});
	m_window.display();
}

void app::sys::RenderSystem::sortLayers(app::Registry & registry, app::Entity entity)
{
	registry.sort<comp::Layer>([&](comp::Layer const & lhs, comp::Layer const & rhs) { return lhs.zIndex < rhs.zIndex; });
}
