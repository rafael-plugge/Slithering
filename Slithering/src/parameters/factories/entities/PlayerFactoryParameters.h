#ifndef _PLAYER_FACTORY_PARAMETERS_H
#define _PLAYER_FACTORY_PARAMETERS_H

#include <src/parameters/factories/base/EntityFactoryParameters.h>

namespace app::par::fact::ent
{
	struct PlayerFactoryParameters : public EntityFactoryParameters
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		math::Vector2f position;
		std::uint16_t zIndex;
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

#endif // !_PLAYER_FACTORY_PARAMETERS_H
