#pragma once

#include <src/factories/entities/SnakeFactory.h>
#include <src/parameters/factories/entities/FsmFactoryParameters.h>

namespace app::fact::ent
{
	class FsmFactory : public SnakeFactory
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
		using Parameters = app::par::fact::ent::FsmFactoryParameters;
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		FsmFactory(Parameters & params);
		virtual ~FsmFactory() = default;

		FsmFactory(FsmFactory const&) = default;

		FsmFactory(FsmFactory&&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity const create() override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		SnakeFactory::Parameters const& m_snakeParams;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		FsmFactory::Parameters const& m_params;
	};

	static_assert(std::is_destructible<FsmFactory>::value, "FsmFactory must be destructible");
	static_assert(std::is_copy_constructible<FsmFactory>::value, "FsmFactory must be copy constructible");
	static_assert(std::is_move_constructible<FsmFactory>::value, "FsmFactory must be move constructible");
}
