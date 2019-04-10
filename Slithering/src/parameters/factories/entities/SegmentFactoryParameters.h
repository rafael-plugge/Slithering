#ifndef _SEGMENT_FACTORY_PARAMETERS_H
#define _SEGMENT_FACTORY_PARAMETERS_H

#include <src/parameters/factories/entities/ImageFactoryParameters.h>

namespace app::par::fact::ent
{
	struct SegmentFactoryParameters
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		par::fact::ent::ImageFactoryParameters imageFactoryParams;
		std::optional<app::Entity> head, tail;
		math::Vector2f offset;
		std::float_t speed;
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

#endif // !_SEGMENT_FACTORY_PARAMETERS_H
