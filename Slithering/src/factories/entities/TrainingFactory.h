#pragma once

#include <src/factories/base/EntityFactory.h>
#include <src/parameters/factories/entities/TrainingFactoryParameters.h>

namespace app::fact::ent
{
	class TrainingFactory : public EntityFactory
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
		using Parameters = par::fact::ent::TrainingFactoryParameters;
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		TrainingFactory(Parameters & params);
		virtual ~TrainingFactory() = default;

		TrainingFactory(TrainingFactory const&) = default;
		TrainingFactory& operator=(TrainingFactory const&) = default;

		TrainingFactory(TrainingFactory&&) = default;
		TrainingFactory& operator=(TrainingFactory&&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity const create() override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		EntityFactory::Parameters const& m_entityParams;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
		Parameters const& m_params;
	};

}
