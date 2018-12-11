#ifndef _FACTORIES_PLAYER_H
#define _FACTORIES_PLAYER_H

#include <src/factories/EntityFactory.h>

namespace app::fact
{
	class PlayerFactory : public EntityFactory
	{
	public: // Constructors/Destructor/Assignments
		PlayerFactory() = default;
		~PlayerFactory() = default;

		PlayerFactory(PlayerFactory const &) = default;
		PlayerFactory & operator=(PlayerFactory const &) = default;

		PlayerFactory(PlayerFactory &&) = default;
		PlayerFactory & operator=(PlayerFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual std::optional<app::Entity> create() override;
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
	};
}

#endif // !_FACTORIES_PLAYER_H
