#ifndef _CAMERA_FACTORY_H
#define _CAMERA_FACTORY_H

#include <src/factories/base/EntityFactory.h>
#include <src/parameters/factories/entities/CameraFactoryParameters.h>

namespace app::fact::ent
{
	class CameraFactory : public EntityFactory
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		using Parameters = par::fact::ent::CameraFactoryParameters;
	public: // Constructors/Destructor/Assignments
		CameraFactory(Parameters & params);
		virtual ~CameraFactory() = default;

		CameraFactory(CameraFactory const &) = default;
		CameraFactory & operator=(CameraFactory const &) = default;

		CameraFactory(CameraFactory &&) = default;
		CameraFactory & operator=(CameraFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity const create() final override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		Parameters const & m_params;
	};
}

#endif // !_CAMERA_FACTORY_H
