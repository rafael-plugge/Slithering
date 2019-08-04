#ifndef _GAME_FACTORY_H
#define _GAME_FACTORY_H

#include "base/BaseFactory.h"

namespace app::fact
{
	class GameFactory : public BaseFactory<std::vector<app::Entity>>
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		GameFactory() = default;
		virtual ~GameFactory() = default;

		GameFactory(GameFactory const &) = default;
		GameFactory & operator=(GameFactory const &) = default;

		GameFactory(GameFactory &&) = default;
		GameFactory & operator=(GameFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual std::vector<app::Entity> create() final override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
		void insertInto(std::vector<app::Entity> & entities, std::vector<app::Entity> insert);
	private: // Private Member Functions
		std::vector<app::Entity> createCameras();
		std::vector<app::Entity> createImages();
		std::vector<app::Entity> createPlayer();
		std::vector<app::Entity> createAi();
		std::vector<app::Entity> createSnake();
		std::vector<app::Entity> createFood();
		std::vector<app::Entity> createWorld();
	private: // Private Static Variables
	private: // Private Member Variables
		std::optional<app::Entity> m_cameraTarget;
		std::optional<app::Entity> m_minimapCamera;
	};
}

#endif // !_GAME_FACTORY_H
