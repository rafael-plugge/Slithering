#include "stdafx.h"
#include <src/systems/RenderSystem.h>

#include <src/visitors/RenderVisitor.h>

// components
#include <src/components/Location.h>
#include <src/components/Dimension.h>
#include <src/components/Render.h>

app::sys::RenderSystem::RenderSystem()
	: BaseSystem()
	, m_renderShape(sf::Vector2f{ 10.0f, 10.0f })
	, m_contextSettings(24u, 8u, 16u, 1u, 1u, sf::ContextSettings::Attribute::Default, false)
	, m_window(sf::VideoMode(1366u, 768u, 32u), "Slithering", sf::Style::Default, m_contextSettings)
	, m_event()
{
}

app::sys::RenderSystem::~RenderSystem()
{
	if (m_window.isOpen()) { m_window.close(); }
}

void app::sys::RenderSystem::pollEvents(app::inp::KeyHandler<sf::Keyboard::Key>& keyHandler, app::inp::MouseHandler<sf::Mouse::Button>& mouseHandler)
{
	using EventType = sf::Event::EventType;
	while (m_window.pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case EventType::Closed:
			m_window.close();
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

void app::sys::RenderSystem::update(app::time::nanoseconds const & dt)
{
	m_window.clear({ 0u, 0u, 0u, 255u });
	m_registry.view<comp::Location, comp::Dimension, comp::Render>()
		.each([this](app::Entity const entity, comp::Location & location, comp::Dimension & dimension, comp::Render & render)
	{
		m_renderShape.setPosition(location.position.x, location.position.y);
		m_renderShape.setRotation(location.angle);
		std::visit(vis::RenderVisitor{ m_renderShape }, render.fill);
		m_renderShape.setSize({ dimension.size.x, dimension.size.y });
		m_renderShape.setOrigin(dimension.origin.x, dimension.origin.y);
		m_window.draw(m_renderShape);
	});
	m_window.display();
}
