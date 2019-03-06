#ifndef _COMP_RENDER_H
#define _COMP_RENDER_H

namespace app::comp
{
	struct Render
	{
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
		static void apply(app::Registry & registry, app::Entity const entity
			, std::variant<std::shared_ptr<sf::Texture>, sf::Color> fill = sf::Color::White
			, std::optional<sf::IntRect> source = std::nullopt
			, math::Vector2f border = math::Vector2f()
			, math::Vector2f offset = math::Vector2f()
		);
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::variant<std::shared_ptr<sf::Texture>, sf::Color> fill;
		std::optional<sf::IntRect> source;
		math::Vector2f border;
		math::Vector2f offset;
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

#endif // !_COMP_RENDER_H
