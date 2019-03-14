#pragma once

#include "BaseSystem.h"

namespace app::sys
{
	class CommandSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		CommandSystem() = default;
		virtual ~CommandSystem() = default;

		CommandSystem(CommandSystem const &) = default;
		CommandSystem & operator=(CommandSystem const &) = default;

		CommandSystem(CommandSystem &&) = default;
		CommandSystem & operator=(CommandSystem &&) = default;

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

	static_assert(std::is_default_constructible<CommandSystem>::value, "CommandSystem must be default constructible");
	static_assert(std::is_destructible<CommandSystem>::value, "CommandSystem must be destructible");
	static_assert(std::is_copy_constructible<CommandSystem>::value, "CommandSystem must be copy constructible");
	static_assert(std::is_copy_assignable<CommandSystem>::value, "CommandSystem must be copy assignable");
	static_assert(std::is_move_constructible<CommandSystem>::value, "CommandSystem must be move constructible");
	static_assert(std::is_move_assignable<CommandSystem>::value, "CommandSystem must be move assignable");
}
