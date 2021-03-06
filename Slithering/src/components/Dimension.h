﻿#ifndef _COMP_DIMENSION_H
#define _COMP_DIMENSION_H

#include <src/math/Vector2.h>

namespace app::comp
{
	struct Dimension
	{
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
		static void apply(app::Registry & registry, app::Entity const entity, math::Vector2f size = math::Vector2f(), std::optional<math::Vector2f> origin = std::nullopt);
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
