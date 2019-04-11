#pragma once

#include "BaseSystem.h"

namespace app::sys
{
	class DestroySystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		DestroySystem() = default;
		virtual ~DestroySystem() = default;

		DestroySystem(DestroySystem const &) = default;
		DestroySystem & operator=(DestroySystem const &) = default;

		DestroySystem(DestroySystem &&) = default;
		DestroySystem & operator=(DestroySystem &&) = default;

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

	static_assert(std::is_default_constructible<DestroySystem>::value, "DestroySystem must be default constructible");
	static_assert(std::is_destructible<DestroySystem>::value, "DestroySystem must be destructible");
	static_assert(std::is_copy_constructible<DestroySystem>::value, "DestroySystem must be copy constructible");
	static_assert(std::is_copy_assignable<DestroySystem>::value, "DestroySystem must be copy assignable");
	static_assert(std::is_move_constructible<DestroySystem>::value, "DestroySystem must be move constructible");
	static_assert(std::is_move_assignable<DestroySystem>::value, "DestroySystem must be move assignable");
}
