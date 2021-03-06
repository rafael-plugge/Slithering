﻿#ifndef _FACTORIES_ENTITY_H
#define _FACTORIES_ENTITY_H

#include "BaseFactory.h"
#include <src/parameters/factories/base/EntityFactoryParameters.h>

namespace app::fact
{
	class EntityFactory : public BaseFactory<app::Entity const>
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
		using Parameters = par::fact::EntityFactoryParameters;
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		EntityFactory(Parameters & params);
		~EntityFactory() = default;

		EntityFactory(EntityFactory const & other);
		EntityFactory & operator=(EntityFactory const & other);

		EntityFactory(EntityFactory &&) = default;
		EntityFactory & operator=(EntityFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity const create() override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		app::Registry & m_registry;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		Parameters & m_params;
	};
}

#endif // !_FACTORIES_ENTITY_H
