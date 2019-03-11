#ifndef _FACTORIES_PLAYER_H
#define _FACTORIES_PLAYER_H

#include <src/factories/entities/SnakeFactory.h>
#include <src/parameters/factories/entities/PlayerFactoryParameters.h>

namespace app::fact::ent
{
	class PlayerFactory : public SnakeFactory
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
		using Parameters = app::par::fact::ent::PlayerFactoryParameters;
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		PlayerFactory(Parameters & params);
		~PlayerFactory() = default;

		PlayerFactory(PlayerFactory const &) = default;
		PlayerFactory & operator=(PlayerFactory const &) = default;

		PlayerFactory(PlayerFactory &&) = default;
		PlayerFactory & operator=(PlayerFactory &&) = default;

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

#endif // !_FACTORIES_PLAYER_H
