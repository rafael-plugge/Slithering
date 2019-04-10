#pragma once

#include "BaseSystem.h"
// components
#include <src/components/Location.h>
#include <src/components/Motion.h>
#include <src/components/Segment.h>

namespace app::sys
{
	class SegmentSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		struct SnakeSection
		{
			app::comp::Segment & segment;
			app::comp::Location & location;
			app::comp::Motion & motion;
		};
	public: // Constructors/Destructor/Assignments
		SegmentSystem() = default;
		virtual ~SegmentSystem() = default;

		SegmentSystem(SegmentSystem const &) = default;
		SegmentSystem & operator=(SegmentSystem const &) = default;

		SegmentSystem(SegmentSystem &&) = default;
		SegmentSystem & operator=(SegmentSystem &&) = default;

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
		constexpr static bool DEBUG_MODE = BaseSystem::DEBUG_MODE && true;
	private: // Private Member Variables
	};

	static_assert(std::is_default_constructible<SegmentSystem>::value, "SegmentSystem must be default constructible");
	static_assert(std::is_destructible<SegmentSystem>::value, "SegmentSystem must be destructible");
	static_assert(std::is_copy_constructible<SegmentSystem>::value, "SegmentSystem must be copy constructible");
	static_assert(std::is_copy_assignable<SegmentSystem>::value, "SegmentSystem must be copy assignable");
	static_assert(std::is_move_constructible<SegmentSystem>::value, "SegmentSystem must be move constructible");
	static_assert(std::is_move_assignable<SegmentSystem>::value, "SegmentSystem must be move assignable");
}
