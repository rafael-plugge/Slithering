#include "stdafx.h"
#include "NeuralNetworkSystem.h"

#include <src/tags/Player.h>
// components
#include <src/components/Location.h>
#include <src/components/Food.h>
#include <src/components/NeuraNetwork.h>
#include <src/components/Destroy.h>
#include <src/components/Commandable.h>

// Internal functions only available in this cpp file
namespace app::sys::internal
{
	std::optional<app::math::Vector2f> findClosestFood(comp::Location const& fsmLocation, std::vector<math::Vector2f> const& foodLocations) noexcept
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
	
	std::vector<app::math::Vector2f> getFoodLocations(app::Registry & registry)
	{
		auto foodLocations = std::vector<math::Vector2f>();
		auto const foodView = registry.view<comp::Food, comp::Location>(entt::persistent_t());
		// make sure not to pick a food to be deleted.
		auto const eatenFoodView = registry.view<comp::Food, comp::Location, comp::Destroy>(entt::persistent_t());

		foodLocations.reserve(foodView.size());
		foodView.each([&](app::Entity const entity, comp::Food const& food, comp::Location const& location) -> void
		{
			if (eatenFoodView.contains(entity)) { return; }
			foodLocations.push_back(location.position);
		});

		return std::move(foodLocations);
	}
	
	nn::OutputData nnDecision(nn::Network& nn, math::Vector2f const& nnPosition, float const & nnOrientation, math::Vector2f const& targetFoodLocation)
	{
		auto input = nn::InputData();
		input = nnPosition.x, nnPosition.y
			, nnOrientation
			, targetFoodLocation.x, targetFoodLocation.y;
		return nn(input);
	}

	long const nnMostConfidentRow(nn::OutputData const& data)
	{
		nn::Type result = data(0L); long row = 0L;
		for (long r = 1L; r < data.nr(); ++r)
			if (result < data(r)) { result = data(r); row = r; }
		return row;
	}

	inp::Command const& nnSelectCommand(long const& rowDecided, std::array<inp::Command, 3> commands)
	{
		if (rowDecided > 2L || rowDecided < 0L) { return commands.back(); }
		return commands.at(rowDecided);
	}
}

void app::sys::NeuralNetworkSystem::init()
{

}

void app::sys::NeuralNetworkSystem::update(app::time::seconds const & dt)
{
	std::vector<math::Vector2f> const foodLocations = internal::getFoodLocations(m_registry);
	m_registry.view<comp::NeuralNetwork, comp::Location, comp::Commandable>()
		.each([&, this](app::Entity const entity, comp::NeuralNetwork & nn, comp::Location const & nnLocation, comp::Commandable & nnCommandable)
	{
		nn::Network & mlp = *nn.pMlp;

		if (nn.neareastFood.has_value() && std::find(foodLocations.cbegin(), foodLocations.cend(), nn.neareastFood.value()) != foodLocations.cend())
		{
			nn::OutputData output = internal::nnDecision(*nn.pMlp, nnLocation.position, nnLocation.orientation, nn.neareastFood.value());
			long const selectedRow = internal::nnMostConfidentRow(output);
			nnCommandable.runOnce.push({ nn.commands.at(selectedRow > nn.commands.size() ? 0 : selectedRow) });
		}
		else
		{
			nn.neareastFood = internal::findClosestFood(nnLocation, foodLocations);
		}
	});
}
