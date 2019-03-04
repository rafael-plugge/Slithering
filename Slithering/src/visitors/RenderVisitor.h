﻿#ifndef _RENDER_VISITOR_H
#define _RENDER_VISITOR_H

namespace app::vis
{
	class RenderVisitor
	{
	public: // Constructors/Destructor/Assignments
		RenderVisitor(sf::RectangleShape & rectangleShape);

		RenderVisitor() = delete;
		RenderVisitor(RenderVisitor const &) = default;
		RenderVisitor(RenderVisitor &&) = default;

		~RenderVisitor() = default;

		RenderVisitor & operator=(RenderVisitor const &) = default;
		RenderVisitor & operator=(RenderVisitor &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		void operator()(sf::Color const & color);
		void operator()(std::shared_ptr<sf::Texture> sptrTexture);
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
		sf::RectangleShape & m_rectangleShape;
	};
}

#endif // !_RENDER_VISITOR_H
