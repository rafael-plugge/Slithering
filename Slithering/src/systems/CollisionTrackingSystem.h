#pragma once

#include "BaseSystem.h"

namespace app::sys
{
	class CollisionTrackingSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		CollisionTrackingSystem() = default;
		virtual ~CollisionTrackingSystem() = default;

		CollisionTrackingSystem(CollisionTrackingSystem const &) = default;
		CollisionTrackingSystem & operator=(CollisionTrackingSystem const &) = default;

		CollisionTrackingSystem(CollisionTrackingSystem &&) = default;
		CollisionTrackingSystem & operator=(CollisionTrackingSystem &&) = default;

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
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	static_assert(std::is_default_constructible<CollisionTrackingSystem>::value, "CollisionTrackingSystem must be default constructible");
	static_assert(std::is_destructible<CollisionTrackingSystem>::value, "CollisionTrackingSystem must be destructible");
	static_assert(std::is_copy_constructible<CollisionTrackingSystem>::value, "CollisionTrackingSystem must be copy constructible");
	static_assert(std::is_copy_assignable<CollisionTrackingSystem>::value, "CollisionTrackingSystem must be copy assignable");
	static_assert(std::is_move_constructible<CollisionTrackingSystem>::value, "CollisionTrackingSystem must be move constructible");
	static_assert(std::is_move_assignable<CollisionTrackingSystem>::value, "CollisionTrackingSystem must be move assignable");
}
