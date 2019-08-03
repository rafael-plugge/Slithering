#pragma once

#include <src/math/Rect.h>
#include <src/math/Math.h>

namespace app::math
{
	template<typename T> constexpr bool isIntersecting(math::Rect<T> const & left, math::Rect<T> const & right)
	{
		return left.x < right.x + right.w && left.x + left.w > right.x
			&& left.y < right.y + right.h && left.y + left.h > right.y;
	}
	template<typename T> constexpr bool isIntersecting(math::Rect<T> const & rect, math::Vector2<T> const & v)
	{
		return rect.x < v.x && rect.x + rect.w > v.x
			&& rect.y < v.y && rect.y + rect.h > v.y;
	}

	template<typename T> constexpr std::optional<std::pair<std::optional<bool>, std::optional<bool>>> isOutOfBounds(math::Rect<T> const & left, math::Rect<T> const & right)
	{
		if (isIntersecting(left, right)) { return std::nullopt; }

		auto result = std::pair<std::optional<bool>, std::optional<bool>>();
		
		if (left.x > right.x + right.w) { result.first = true; }
		else if (left.x + left.w < right.x) { result.first = false; }
		else { result.first.reset(); }

		if (left.y > right.y + right.h) { result.second = true; }
		else if (left.y + left.h < right.y) { result.second = false; }
		else { result.second.reset(); }

		return std::move(result);
	}
}