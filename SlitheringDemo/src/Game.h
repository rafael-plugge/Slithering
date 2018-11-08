#ifndef _GAME_H
#define _GAME_H

#include "systems/BaseSystem.h"

#include "utilities/Time.h"
#include "utilities/Registry.h"
#include "utilities/Console.h"

#include "input/Keyhandler.h"
#include "input/MouseHandler.h"

namespace app
{
	class Game
	{
	public: // Constructors/Destructor/Assignments
		Game();
		Game(Game const &) = delete;
		Game(Game &&) = delete;

		~Game();

		Game & operator=(Game const &) = delete;
		Game & operator=(Game &&) = delete;

	public: // Public Static Functions
	public: // Public Member Functions
		int run();
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
		bool init();
		
		bool createSystems();
		bool createEntities();

		void pollEvents();
		void update(app::time::nanoseconds const & dt);
		void render(app::time::nanoseconds const & dt);
	private: // Private Static Variables
	private: // Private Member Variables
		bool m_gameLoop;
		app::Registry & m_registry;
		inp::KeyHandler<sf::Keyboard::Key> m_keyHandler;
		inp::MouseHandler m_mouseHandler;
		std::array<std::unique_ptr<sys::BaseSystem>, 2> m_updateSystems;
		std::array<std::unique_ptr<sys::BaseSystem>, 1> m_renderSystems;
	};
}

#endif // !_GAME_H
