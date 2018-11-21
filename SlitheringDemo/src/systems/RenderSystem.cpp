#include "stdafx.h"
#include "RenderSystem.h"

#include "visitors/RenderVisitor.h"

// components
#include "components/Location.h"
#include "components/Dimension.h"
#include "components/Render.h"

app::sys::RenderSystem::RenderSystem()
	: BaseSystem()
	, m_renderShape(sf::Vector2f{ 10.0f, 10.0f })
	, m_contextSettings(8u, 8u, 32u, 1u, 1u, sf::ContextSettings::Attribute::Default, false)
	, m_window(sf::VideoMode(1366u, 768u, 32u), "Slithering", sf::Style::Default, m_contextSettings)
{
}

app::sys::RenderSystem::~RenderSystem()
{
	if (m_window.isOpen()) { m_window.close(); }
}

void app::sys::RenderSystem::update(app::time::nanoseconds const & dt)
{
	m_registry.view<comp::Location, comp::Dimension, comp::Render>()
		.each([this](app::Entity const entity, comp::Location & location, comp::Dimension & dimension, comp::Render & render)
	{
		m_renderShape.setPosition(location.position.x, location.position.y);
		m_renderShape.setRotation(location.angle);
		std::visit(vis::RenderVisitor{ m_renderShape }, render.fill);
		m_renderShape.setSize(dimension.size);
		m_renderShape.setOrigin(dimension.origin);
		m_window.draw(m_renderShape);
	});
}
