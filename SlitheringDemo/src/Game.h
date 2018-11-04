#ifndef _GAME_H
#define _GAME_H

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
		void update();
		void render();
	private: // Private Static Variables
	private: // Private Member Variables

	};
}

#endif // !_GAME_H
