#ifndef _MOTION_SYSTEM_H
#define _MOTION_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class MotionSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		MotionSystem() = default;
		virtual ~MotionSystem() = default;

		MotionSystem(MotionSystem const &) = default;
		MotionSystem & operator=(MotionSystem const &) = default;

		MotionSystem(MotionSystem &&) = default;
		MotionSystem & operator=(MotionSystem &&) = default;

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
}

#endif // !_MOTION_SYSTEM_H
