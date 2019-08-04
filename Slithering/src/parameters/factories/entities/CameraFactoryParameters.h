#ifndef _CAMERA_FACTORY_PARAMETERS_H
#define _CAMERA_FACTORY_PARAMETERS_H

#include "../base/EntityFactoryParameters.h"
#include <src/math/Rect.h>

namespace app::par::fact::ent
{
	struct CameraFactoryParameters
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		math::Vector2f position, size;
		math::Rectf viewport;
		std::optional<app::Entity> target;
		std::uint16_t baseIndex;
		EntityFactoryParameters entityFactoryParams;
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

#endif // !_CAMERA_FACTORY_PARAMETERS_H
