#ifndef _BASE_SYSTEM_H
#define _BASE_SYSTEM_H

#include <src/utilities/Time.h>

namespace app::sys
{
	class BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		BaseSystem();
		~BaseSystem() = default;

		BaseSystem(BaseSystem const & other);
		BaseSystem & operator=(BaseSystem const & other);

		BaseSystem(BaseSystem &&) = default;
		BaseSystem & operator=(BaseSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void init() abstract;
		virtual void update(app::time::seconds const & dt) abstract;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
		constexpr static bool DEBUG_MODE = app::Console::DEBUG_MODE && true;
	protected: // Protected Member Variables
		app::Registry & m_registry;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	static_assert(std::is_destructible<BaseSystem>::value, "BaseSystem must be destructible");
	static_assert(std::is_copy_assignable<BaseSystem>::value, "BaseSystem must be copy assignable");
	static_assert(std::is_move_assignable<BaseSystem>::value, "BaseSystem must be move assignable");
}

#endif // !_BASE_SYSTEM_H
