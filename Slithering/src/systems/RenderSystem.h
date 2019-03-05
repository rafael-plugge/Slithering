#ifndef _RENDER_SYSTEM_H
#define _RENDER_SYSTEM_H

#include <src/systems/BaseSystem.h>

namespace app::sys
{
	class RenderSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		struct Default
		{
			struct ContextSettings
			{
				constexpr static std::uint32_t DEPTH_BUFFER_BITS = 24u;
				constexpr static std::uint32_t STENCIL_BUFFER_BITS = 8u;
				constexpr static std::uint32_t ANTIALIASING = 16u;
				constexpr static std::uint32_t MAJOR_VERSION = 1u;
				constexpr static std::uint32_t MINOR_VERSION = 1u;
				constexpr static auto ATTRIBUTE = sf::ContextSettings::Attribute::Default;
				constexpr static bool SRGB_CAPABLE = false;
			};
			struct Window
			{
				constexpr static auto TITLE = "Slithering";
				struct VideoMode
				{
					constexpr static std::uint32_t WIDTH = 1366u;
					constexpr static std::uint32_t HEIGHT = 768u;
					constexpr static std::uint32_t BITS_PER_PIXEL = 32u;
				};
				constexpr static auto STYLE = sf::Style::Default;
			};
		};
	public: // Constructors/Destructor/Assignments
		RenderSystem(bool & running);

		virtual ~RenderSystem();

		RenderSystem(RenderSystem const &) = default;
		RenderSystem(RenderSystem &&) = default;

		RenderSystem & operator=(RenderSystem const &) = default;
		RenderSystem & operator=(RenderSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		void pollEvents(app::inp::KeyHandler & keyHandler, app::inp::MouseHandler & mouseHandler);
		virtual void init() final override;
		virtual void update(app::time::seconds const & dt) final override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		bool & m_running;
		sf::RectangleShape m_renderShape;
		sf::ContextSettings m_contextSettings;
		sf::RenderWindow m_window;
		sf::RenderStates const m_renderState;
		sf::Event m_event;
		sf::View m_view;
	private: // Private Static Functions
		static void sortLayers(app::Registry & registry, app::Entity entity);
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_RENDER_SYSTEM_H
