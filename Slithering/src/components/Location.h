#ifndef _COMP_LOCATION_H
#define _COMP_LOCATION_H

#include <src/math/Vector2.h>

namespace app::comp
{
	struct Location
	{
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
		static void apply(app::Registry & registry, app::Entity const entity, math::Vector2f position = math::Vector2f(), std::float_t orientation = 0.0f);
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		math::Vector2f position;
		std::float_t orientation;
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

#endif // !_COMP_LOCATION_H
