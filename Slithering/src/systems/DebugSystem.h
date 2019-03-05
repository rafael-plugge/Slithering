#ifndef _DEBUG_SYSTEM_H
#define _DEBUG_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class DebugSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		DebugSystem() = default;
		virtual ~DebugSystem() = default;

		DebugSystem(DebugSystem const &) = default;
		DebugSystem & operator=(DebugSystem const &) = default;

		DebugSystem(DebugSystem &&) = default;
		DebugSystem & operator=(DebugSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		// Inherited via BaseSystem
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
		constexpr static bool DEBUG_MODE = app::cout::DEBUG_MODE && false;
	private: // Private Member Variables
	};
}

#endif // !_DEBUG_SYSTEM_H
