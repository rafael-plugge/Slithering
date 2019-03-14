#ifndef _GAME_H
#define _GAME_H

#include <src/utilities/Time.h>
#include <src/utilities/Console.h>
#include <src/factories/GameFactory.h>

#include <src/systems/BaseSystem.h>

// update systems
#include <src/systems/DebugSystem.h>
#include <src/systems/InputSystem.h>
#include <src/systems/MotionSystem.h>
#include <src/systems/CameraTrackingSystem.h>
#include <src/systems/SegmentSystem.h>
#include <src/systems/CommandSystem.h>

// render systems
#include <src/systems/RenderSystem.h>

namespace app
{
	class Game
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		using UpdateSystem = std::variant<
			  sys::DebugSystem
			, sys::InputSystem
			, sys::MotionSystem
			, sys::CameraTrackingSystem
			, sys::SegmentSystem
			, sys::CommandSystem
		>;
		using UpdateSystems = std::array<UpdateSystem, 6>;
		using RenderSystem = std::variant<
			  sys::RenderSystem
		>;
		using RenderSystems = std::array<RenderSystem, 1>;
	public: // Constructors/Destructor/Assignments
		Game();
		~Game();

		Game(Game const &) = delete;
		Game(Game &&) = delete;

		Game & operator=(Game const &) = delete;
		Game & operator=(Game &&) = delete;

	public: // Public Static Functions
	public: // Public Member Functions
		bool init();
		constexpr bool const & isRunning() const { return m_gameLoop; }
		void pollEvents();
		void update(app::time::seconds const & dt);
		void render(app::time::seconds const & dt);

	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
		bool initSystems();
		bool createEntities();
		bool aiTrainingExample();

	private: // Private Static Variables
	private: // Private Member Variables
		bool m_gameLoop;
		app::Registry & m_registry;
		inp::KeyHandler m_keyHandler;
		inp::MouseHandler m_mouseHandler;
		UpdateSystems m_updateSystems;
		RenderSystems m_renderSystems;
		fact::GameFactory m_gameFactory;
	};
}

#endif // !_GAME_H
