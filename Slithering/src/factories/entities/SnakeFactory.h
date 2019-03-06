#ifndef _SNAKE_FACTORY_H
#define _SNAKE_FACTORY_H

#include "../base/EntityFactory.h"
#include <src/factories/entities/ImageFactory.h>
#include <src/parameters/factories/entities/SnakeFactoryParameters.h>

namespace app::fact::ent
{
	class SnakeFactory : public ImageFactory
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		using Parameters = app::par::fact::ent::SnakeFactoryParameters;
	public: // Constructors/Destructor/Assignments
		SnakeFactory(Parameters const & params);
		virtual ~SnakeFactory() = default;

		SnakeFactory(SnakeFactory const &) = default;
		SnakeFactory & operator=(SnakeFactory const &) = default;

		SnakeFactory(SnakeFactory &&) = default;
		SnakeFactory & operator=(SnakeFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity const create() final override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		ImageFactory::Parameters const & m_imageParams;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		SnakeFactory::Parameters const & m_params;
	};
}

#endif // !_SNAKE_FACTORY_H
