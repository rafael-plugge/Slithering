#include "stdafx.h"
#include "MouseHandler.h"

app::inp::MouseHandler::MouseHandler()
	: m_keyNowMap()
	, m_keyPrevMap()
	, m_mouse(0, 0)
{
}

app::inp::MouseHandler::~MouseHandler()
{
}

void app::inp::MouseHandler::updateButton(std::uint8_t const & buttonIndex, bool const & pressed)
{
	if (auto const & itt = m_keyNowMap.find(static_cast<MouseHandler::ButtonType>(buttonIndex)); itt != m_keyNowMap.end())
	{
		auto &[key, value] = *itt;
		value = pressed;
		m_keyPrevMap[key] = !pressed;
	}
	else
	{
		m_keyNowMap.insert({ static_cast<MouseHandler::ButtonType>(buttonIndex), pressed });
		m_keyPrevMap.insert({ static_cast<MouseHandler::ButtonType>(buttonIndex), !pressed });
	}
}

void app::inp::MouseHandler::updatePosition(std::int32_t const & x, std::int32_t const & y)
{
	m_mouse.x = x;
	m_mouse.y = y;
}

bool app::inp::MouseHandler::isButtonDown(ButtonType const & button) const
{
	return app::inp::MouseHandler::isButtonDown(m_keyNowMap, button);
}

bool app::inp::MouseHandler::isButtonDown(std::initializer_list<ButtonType> const & buttons) const
{
	return app::inp::MouseHandler::isButtonDown(m_keyNowMap, buttons);
}

bool app::inp::MouseHandler::isButtonUp(ButtonType const & button) const
{
	return app::inp::MouseHandler::isButtonUp(m_keyNowMap, button);
}

bool app::inp::MouseHandler::isButtonUp(std::initializer_list<ButtonType> const & buttons) const
{
	return app::inp::MouseHandler::isButtonUp(m_keyNowMap, buttons);
}

bool app::inp::MouseHandler::isButtonPressed(ButtonType const & button) const
{
	return app::inp::MouseHandler::isButtonUp(m_keyPrevMap, button) && app::inp::MouseHandler::isButtonDown(m_keyNowMap, button);
}

bool app::inp::MouseHandler::isButtonPressed(std::initializer_list<ButtonType> const & buttons) const
{
	return app::inp::MouseHandler::isButtonUp(m_keyPrevMap, buttons) && app::inp::MouseHandler::isButtonDown(m_keyNowMap, buttons);
}

inline bool app::inp::MouseHandler::isButtonDown(MouseHandler::map const & keyMap, ButtonType const & button)
{
	using pair = std::pair<MouseHandler::map::key_type, MouseHandler::map::mapped_type>;
	const auto predicate = [&button](pair const & p) constexpr { return p.first == button && p.second; };
	return std::find_if(keyMap.begin(), keyMap.end(), predicate) != keyMap.end();
}

inline bool app::inp::MouseHandler::isButtonDown(MouseHandler::map const & keyMap, std::initializer_list<ButtonType> const & buttons)
{
	using pair = std::pair<MouseHandler::map::key_type, MouseHandler::map::mapped_type>;
	const auto predicate = [&buttons](pair const & p) constexpr
	{
		return p.second &&
			std::find_if(buttons.begin(), buttons.end(), [&p](ButtonType const & button) constexpr { return p.first == button; }) != buttons.end();
	};
	return std::find_if(keyMap.begin(), keyMap.end(), predicate) != keyMap.end();
}

inline bool app::inp::MouseHandler::isButtonUp(MouseHandler::map const & keyMap, ButtonType const & button)
{
	using pair = std::pair<MouseHandler::map::key_type, MouseHandler::map::mapped_type>;
	const auto predicate = [&button](pair const & p) constexpr { return p.first == button && !p.second; };
	return std::find_if(keyMap.begin(), keyMap.end(), predicate) != keyMap.end();
}

inline bool app::inp::MouseHandler::isButtonUp(MouseHandler::map const & keyMap, std::initializer_list<ButtonType> const & buttons)
{
	using pair = std::pair<MouseHandler::map::key_type, MouseHandler::map::mapped_type>;
	const auto predicate = [&buttons](pair const & p) constexpr
	{
		return !p.second &&
			std::find_if(buttons.begin(), buttons.end(), [&p](ButtonType const & button) constexpr { return p.first == button; }) != buttons.end();
	};
	return std::find_if(keyMap.begin(), keyMap.end(), predicate) != keyMap.end();
}
