#ifndef _SNAKE_FACTORY_PARAMETERS_H
#define _SNAKE_FACTORY_PARAMETERS_H

#include <src/parameters/factories/entities/ImageFactoryParameters.h>

namespace app::par::fact::ent
{
	struct SnakeFactoryParameters
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
		math::Vector2f offset;
		std::variant<std::shared_ptr<sf::Texture>, sf::Color>
			segmentFill, tailFill;
		std::size_t amount;
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

#endif // !_SNAKE_FACTORY_PARAMETERS_H
