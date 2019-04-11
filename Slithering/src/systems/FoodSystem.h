#pragma once

#include "BaseSystem.h"
#include <src/math/Rect.h>
#include <src/factories/entities/FoodFactory.h>

namespace app::sys
{
	class FoodSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		FoodSystem() = default;
		virtual ~FoodSystem() = default;

		FoodSystem(FoodSystem const &) = default;
		FoodSystem & operator=(FoodSystem const &) = default;

		FoodSystem(FoodSystem &&) = default;
		FoodSystem & operator=(FoodSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void init() final override;
		virtual void update(app::time::seconds const & dt) final override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
		constexpr static bool check(math::Rectf const & left, math::Rectf const & right);
	private: // Private Member Functions
		void onFoodDestruction(app::Registry & registry, app::Entity const entity);
		void spawnFood(math::Vector2f position);
	private: // Private Static Variables
	private: // Private Member Variables
		bool m_foodDestroyed;
		app::par::fact::ent::FoodFactoryParameters m_foodFactoryParams;
		std::optional<app::fact::ent::FoodFactory> m_foodFactory;
	};

	static_assert(std::is_default_constructible<FoodSystem>::value, "FoodSystem must be default constructible");
	static_assert(std::is_destructible<FoodSystem>::value, "FoodSystem must be destructible");
	static_assert(std::is_copy_constructible<FoodSystem>::value, "FoodSystem must be copy constructible");
	static_assert(std::is_move_constructible<FoodSystem>::value, "FoodSystem must be move constructible");
}
