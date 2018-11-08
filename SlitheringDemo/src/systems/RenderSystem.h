#ifndef _RENDER_SYSTEM_H
#define _RENDER_SYSTEM_H

#include "BaseSystem.h"

namespace app::sys
{
	class RenderSystem : public BaseSystem
	{
	public: // Constructors/Destructor/Assignments
		RenderSystem();

		RenderSystem(RenderSystem const &) = default;
		RenderSystem(RenderSystem &&) = default;

		virtual ~RenderSystem();

		RenderSystem & operator=(RenderSystem const &) = default;
		RenderSystem & operator=(RenderSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void update(app::time::nanoseconds const & dt) override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		sf::RectangleShape m_renderShape;
		sf::ContextSettings m_contextSettings;
		sf::RenderWindow m_window;
		sf::RenderStates const m_renderState;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_RENDER_SYSTEM_H
