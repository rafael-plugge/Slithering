#pragma once

#include <src/factories/entities/ImageFactory.h>
#include <src/parameters/factories/entities/FoodFactoryParameters.h>

namespace app::fact::ent
{
	class FoodFactory : public ImageFactory
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
		using Parameters = par::fact::ent::FoodFactoryParameters;
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		FoodFactory(Parameters & params);
		virtual ~FoodFactory() = default;

		FoodFactory(FoodFactory const &) = default;
		FoodFactory & operator=(FoodFactory const &) = default;

		FoodFactory(FoodFactory &&) = default;
		FoodFactory & operator=(FoodFactory &&) = default;

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
		Parameters const & m_params;
	};

	static_assert(std::is_destructible<FoodFactory>::value, "FoodFactory must be destructible");
	static_assert(std::is_copy_constructible<FoodFactory>::value, "FoodFactory must be copy constructible");
	static_assert(std::is_move_constructible<FoodFactory>::value, "FoodFactory must be move constructible");
}
