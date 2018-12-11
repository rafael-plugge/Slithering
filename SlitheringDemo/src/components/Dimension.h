#ifndef _COMP_DIMENSION_H
#define _COMP_DIMENSION_H

#include <src/math/Vector2.h>

namespace app::comp
{
	struct Dimension
	{
	public: // Constructors/Destructor/Assignments
		Dimension() = default;
		Dimension(Dimension const &) = default;
		Dimension(Dimension &&) = default;

		~Dimension() = default;

		Dimension & operator=(Dimension const &) = default;
		Dimension & operator=(Dimension &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		math::Vector2f size;
		math::Vector2f origin;
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

#endif // !_COMP_DIMENSION_H
