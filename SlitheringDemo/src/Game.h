#ifndef _GAME_H
#define _GAME_H

#include <src/systems/BaseSystem.h>

#include <src/utilities/Time.h>
#include <src/utilities/Registry.h>
#include <src/utilities/Console.h>

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
		inp::Keyhandler m_keyHandler;
		inp::Mousehandler m_mouseHandler;
		std::array<std::unique_ptr<sys::BaseSystem>, 0> m_updateSystems;
		std::array<std::unique_ptr<sys::BaseSystem>, 1> m_renderSystems;
		entt::SigH<void(inp::KeyHandler<sf::Keyboard::Key> &, inp::MouseHandler<sf::Mouse::Button> &)> m_pollEventsSignal;
	};
}

#endif // !_GAME_H
