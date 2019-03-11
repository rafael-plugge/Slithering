#ifndef _IMAGE_FACTORY_H
#define _IMAGE_FACTORY_H

#include <src/factories/base/EntityFactory.h>
#include <src/parameters/factories/entities/ImageFactoryParameters.h>

namespace app::fact::ent
{
	class ImageFactory : public EntityFactory
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
		using Parameters = par::fact::ent::ImageFactoryParameters;
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		ImageFactory(Parameters & params);
		virtual ~ImageFactory() = default;

		ImageFactory(ImageFactory const &) = default;
		ImageFactory & operator=(ImageFactory const &) = default;

		ImageFactory(ImageFactory &&) = default;
		ImageFactory & operator=(ImageFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity const create() override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		EntityFactory::Parameters const & m_entityParams;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		Parameters const & m_params;
	};
}

#endif // !_IMAGE_FACTORY_H
