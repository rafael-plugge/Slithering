#pragma once

#include <src/factories/entities/ImageFactory.h>
#include <src/parameters/factories/entities/BorderFactoryParameters.h>

namespace app::fact::ent
{
	class BorderFactory : public ImageFactory
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
		using Parameters = app::par::fact::ent::BorderFactoryParameters;
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		BorderFactory(Parameters & params);
		virtual ~BorderFactory() = default;

		BorderFactory(BorderFactory const &) = default;
		BorderFactory & operator=(BorderFactory const &) = default;

		BorderFactory(BorderFactory &&) = default;
		BorderFactory & operator=(BorderFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity const create() override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		ImageFactory::Parameters const & m_imageParams;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		BorderFactory::Parameters const & m_params;
	};

	static_assert(std::is_destructible<BorderFactory>::value, "BorderFactory must be destructible");
	static_assert(std::is_copy_constructible<BorderFactory>::value, "BorderFactory must be copy constructible");
	static_assert(std::is_move_constructible<BorderFactory>::value, "BorderFactory must be move constructible");
}
