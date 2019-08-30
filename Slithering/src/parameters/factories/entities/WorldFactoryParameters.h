#pragma once

#include <src/parameters/factories/base/EntityFactoryParameters.h>
#include <src/parameters/factories/entities/BorderFactoryParameters.h>
#include <src/math/Rect.h>

namespace app::par::fact::ent
{
	struct WorldFactoryParams
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		EntityFactoryParameters entityFactoryParams;
		math::Rectf bounds;
		BorderFactoryParameters borderFactoryParams;
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
