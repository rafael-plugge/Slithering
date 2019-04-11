#pragma once

#include "SnakeFactory.h"
#include <src/factories/entities/SnakeFactory.h>
#include <src/parameters/factories/entities/AiFactoryParameters.h>

namespace app::fact::ent
{
	class AiFactory : public SnakeFactory
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
		using Parameters = app::par::fact::ent::AiFactoryParameters;
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		AiFactory(Parameters & params);
		virtual ~AiFactory() = default;

		AiFactory(AiFactory const &) = default;
		AiFactory & operator=(AiFactory const &) = default;

		AiFactory(AiFactory &&) = default;
		AiFactory & operator=(AiFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity const create() final override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		SnakeFactory::Parameters const & m_snakeParams;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		Parameters const & m_params;
	};

	static_assert(std::is_destructible<AiFactory>::value, "AiFactory must be destructible");
	static_assert(std::is_copy_constructible<AiFactory>::value, "AiFactory must be copy constructible");
	static_assert(std::is_move_constructible<AiFactory>::value, "AiFactory must be move constructible");
}
