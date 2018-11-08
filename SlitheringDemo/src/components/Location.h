#ifndef _COMP_LOCATION_H
#define _COMP_LOCATION_H

#include "math/Vector2.h"

namespace app::comp
{
	struct Location
	{
	public: // Constructors/Destructor/Assignments
		Location() = default;
		Location(Location const &) = default;
		Location(Location &&) = default;

		~Location() = default;

		Location & operator=(Location const &) = default;
		Location & operator=(Location &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		math::Vector2f position;
		float angle;
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
