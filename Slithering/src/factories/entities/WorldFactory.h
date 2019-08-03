#pragma once

#include <src/factories/base/EntityFactory.h>
#include <src/parameters/factories/entities/WorldFactoryParameters.h>

namespace app::fact::ent
{
	class WorldFactory : public EntityFactory
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
		using Parameters = par::fact::ent::WorldFactoryParams;
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		WorldFactory(Parameters & params);
		virtual ~WorldFactory() = default;

		WorldFactory(WorldFactory const &) = default;
		WorldFactory & operator=(WorldFactory const &) = default;

		WorldFactory(WorldFactory &&) = default;
		WorldFactory & operator=(WorldFactory &&) = default;

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

	static_assert(std::is_destructible<WorldFactory>::value, "WorldFactory must be destructible");
	static_assert(std::is_copy_constructible<WorldFactory>::value, "WorldFactory must be copy constructible");
	static_assert(std::is_move_constructible<WorldFactory>::value, "WorldFactory must be move constructible");
}
