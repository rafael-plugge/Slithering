#ifndef _CAMERA_TRACKING_SYSTEM_H
#define _CAMERA_TRACKING_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class CameraTrackingSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		CameraTrackingSystem() = default;
		virtual ~CameraTrackingSystem() = default;

		CameraTrackingSystem(CameraTrackingSystem const &) = default;
		CameraTrackingSystem & operator=(CameraTrackingSystem const &) = default;

		CameraTrackingSystem(CameraTrackingSystem &&) = default;
		CameraTrackingSystem & operator=(CameraTrackingSystem &&) = default;

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

#endif // !_CAMERA_TRACKING_SYSTEM_H
