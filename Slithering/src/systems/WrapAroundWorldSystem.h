#pragma once

#include "BaseSystem.h"

namespace app::sys
{
	class WrapAroundWorldSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		WrapAroundWorldSystem() = default;
		virtual ~WrapAroundWorldSystem() = default;

		WrapAroundWorldSystem(WrapAroundWorldSystem const &) = default;
		WrapAroundWorldSystem & operator=(WrapAroundWorldSystem const &) = default;

		WrapAroundWorldSystem(WrapAroundWorldSystem &&) = default;
		WrapAroundWorldSystem & operator=(WrapAroundWorldSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void init() override;
		virtual void update(app::time::seconds const & dt) override;
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

	static_assert(std::is_default_constructible<WrapAroundWorldSystem>::value, "WrapAroundWorldSystem must be default constructible");
	static_assert(std::is_destructible<WrapAroundWorldSystem>::value, "WrapAroundWorldSystem must be destructible");
	static_assert(std::is_copy_constructible<WrapAroundWorldSystem>::value, "WrapAroundWorldSystem must be copy constructible");
	static_assert(std::is_copy_assignable<WrapAroundWorldSystem>::value, "WrapAroundWorldSystem must be copy assignable");
	static_assert(std::is_move_constructible<WrapAroundWorldSystem>::value, "WrapAroundWorldSystem must be move constructible");
	static_assert(std::is_move_assignable<WrapAroundWorldSystem>::value, "WrapAroundWorldSystem must be move assignable");
}
