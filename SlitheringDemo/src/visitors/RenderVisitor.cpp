﻿#include "stdafx.h"
#include "RenderVisitor.h"

app::vis::RenderVisitor::RenderVisitor(sf::RectangleShape & rectangleShape)
	: m_rectangleShape(rectangleShape)
{
}

void app::vis::RenderVisitor::operator()(sf::Color const & color)
{
	m_rectangleShape.setFillColor(color);
	m_rectangleShape.setTexture(nullptr, true);
}

void app::vis::RenderVisitor::operator()(std::shared_ptr<sf::Texture> sptrTexture)
{
	m_rectangleShape.setFillColor(sf::Color::White);
	m_rectangleShape.setTexture(sptrTexture.get(), true);
}