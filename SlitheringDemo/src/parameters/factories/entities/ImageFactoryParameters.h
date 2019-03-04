#ifndef _IMAGE_FACTORY_PARAMETERS_H
#define _IMAGE_FACTORY_PARAMETERS_H

#include <src/parameters/factories/base/EntityFactoryParameters.h>

namespace app::par::fact::ent
{
	struct ImageFactoryParameters : public EntityFactoryParameters
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		math::Vector2f position, size, origin;
		std::float_t orientation;
		std::shared_ptr<sf::Texture> texture;
		std::optional<sf::IntRect> source;
		math::Vector2f border, offset;
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

#endif // !_IMAGE_FACTORY_PARAMETERS_H
