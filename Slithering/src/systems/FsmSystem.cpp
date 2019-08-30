#include "stdafx.h"
#include <src/systems/FsmSystem.h>

// components
#include <src/components/FiniteStateMachine.h>
#include <src/components/Location.h>
#include <src/components/Motion.h>
#include <src/components/Food.h>
#include <src/components/Commandable.h>
#include <src/components/Destroy.h>

// misc
#include <src/math/Math.h>

// Internal functions only available in this cpp file
namespace app::sys::internal
{
	void moveToFood(app::Entity const& fsmEntity, comp::Commandable& fsmCommandable, comp::Location const& fsmLocation, comp::Motion const& fsmMotion, math::Vector2f const& foodLocation)
	{
		std::float_t constexpr MARGIN_OF_ERROR = 1.0f; // don't turn if food is within a field of view of 1 degree.
		std::optional<bool> turnLeft = std::nullopt;

		math::Vector2f const& fsmDirectionVector = fsmMotion.direction.has_value()
			? math::toVector(fsmMotion.direction.value())
			: math::toVector(fsmLocation.orientation);
		math::Vector2f const& foodDirectionVector = fsmLocation.position - foodLocation;

		auto const& foodDirectionVectorUnit = foodDirectionVector.unit();

		float const& angleBetweenFsmFood = math::angleBetween(fsmDirectionVector, foodDirectionVector);

		if (angleBetweenFsmFood > MARGIN_OF_ERROR)
			turnLeft.emplace(true);
		else if (angleBetweenFsmFood < -MARGIN_OF_ERROR)
			turnLeft.emplace(false);
		else
			turnLeft.reset();

		if (turnLeft && turnLeft.value()) // turn left
			fsmCommandable.runOnce.push({ app::inp::Command(std::in_place_type<com::TurnLeftCommand>, fsmEntity) });
		else if (turnLeft && !turnLeft.value()) // turn right
			fsmCommandable.runOnce.push({ app::inp::Command(std::in_place_type<com::TurnRightCommand>, fsmEntity) });
		else // don't turn
		{
		}
	}


	std::optional<app::math::Vector2f> findNearestFood(comp::Location const & fsmLocation, std::vector<math::Vector2f> const& foodLocations) noexcept
	{
		if (foodLocations.size() == 0) { app::cout::wrl("No Food found"); return std::nullopt; }

		math::Vector2f closestLocation = foodLocations.front();

		std::for_each(++foodLocations.cbegin(), foodLocations.cend(),
			[&](math::Vector2f const& foodLocation) -> void
		{
			auto const betweenFsmClosest = closestLocation - fsmLocation.position;
			auto const betweenFsmNewFood = foodLocation - fsmLocation.position;

			if (betweenFsmClosest.magnitudeSqr() > betweenFsmNewFood.magnitudeSqr()) { closestLocation = foodLocation; }
		});

		app::cout::wrl({ "Picked food location ", closestLocation });
		return std::move(closestLocation);
	}
}

app::sys::FsmSystem::FsmSystem()
	: BaseSystem()
{
}

void app::sys::FsmSystem::init()
{
	m_registry.prepare<comp::FiniteStateMachine, comp::Commandable, comp::Location, comp::Motion>();
	m_registry.prepare<comp::Food, comp::Location>();
	m_registry.prepare<comp::Food, comp::Location, comp::Destroy>();
}

void app::sys::FsmSystem::update(app::time::seconds const& dt)
{
	std::vector<math::Vector2f> const foodLocations = getFoodLocations();

	m_registry.view<comp::FiniteStateMachine, comp::Commandable, comp::Location, comp::Motion>(entt::persistent_t())
		.each([&, this](app::Entity const fsmEntity, comp::FiniteStateMachine& fsm, comp::Commandable& commandable, comp::Location& location, comp::Motion& motion) -> void
	{
		if (fsm.nearestFood.has_value() && std::find(foodLocations.cbegin(), foodLocations.cend(), fsm.nearestFood.value()) != foodLocations.cend())
			internal::moveToFood(fsmEntity, commandable, location, motion, *fsm.nearestFood);
		else
			fsm.nearestFood = internal::findNearestFood(location, foodLocations);
	});

}

std::vector<app::math::Vector2f> app::sys::FsmSystem::getFoodLocations() const
{
	auto foodLocations = std::vector<math::Vector2f>();
	auto const foodView = m_registry.view<comp::Food, comp::Location>(entt::persistent_t());
	// make sure not to pick a food to be deleted.
	auto const eatenFoodView = m_registry.view<comp::Food, comp::Location, comp::Destroy>(entt::persistent_t());

	foodLocations.reserve(foodView.size());
	foodView.each([&](app::Entity const entity, comp::Food const& food, comp::Location const& location) -> void
	{
		if (eatenFoodView.contains(entity)) { return; }
		foodLocations.push_back(location.position);
	});

	return std::move(foodLocations);
}

