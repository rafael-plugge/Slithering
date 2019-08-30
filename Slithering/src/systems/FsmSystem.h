#pragma once

#include <src/systems/BaseSystem.h>

namespace app::sys
{
	class FsmSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		FsmSystem();
		virtual ~FsmSystem() = default;

		FsmSystem(FsmSystem const&) = default;
		FsmSystem& operator=(FsmSystem const&) = default;

		FsmSystem(FsmSystem&&) = default;
		FsmSystem& operator=(FsmSystem&&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void init() final override;
		virtual void update(app::time::seconds const& dt) final override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
		std::vector<math::Vector2f> getFoodLocations() const;
	private: // Private Static Variables
	private: // Private Member Variables
	};

	static_assert(std::is_default_constructible<FsmSystem>::value, "FsmSystem must be default constructible");
	static_assert(std::is_destructible<FsmSystem>::value, "FsmSystem must be destructible");
	static_assert(std::is_copy_constructible<FsmSystem>::value, "FsmSystem must be copy constructible");
	static_assert(std::is_copy_assignable<FsmSystem>::value, "FsmSystem must be copy assignable");
	static_assert(std::is_move_constructible<FsmSystem>::value, "FsmSystem must be move constructible");
	static_assert(std::is_move_assignable<FsmSystem>::value, "FsmSystem must be move assignable");
}
