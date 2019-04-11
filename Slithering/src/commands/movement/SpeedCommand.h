#pragma once

#include "../base/BaseCommand.h"

namespace app::com
{
	class SpeedCommand : public BaseCommand
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		SpeedCommand(app::Entity targetEntity, std::float_t speedIncrements = 2.0f);
		virtual ~SpeedCommand() = default;

		SpeedCommand(SpeedCommand const &) = default;
		SpeedCommand & operator=(SpeedCommand const &) = default;

		SpeedCommand(SpeedCommand &&) = default;
		SpeedCommand & operator=(SpeedCommand &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void execute() const final override;
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
		app::Entity m_targetEntity;
		std::float_t m_speedIncrements;
	};

	static_assert(std::is_destructible<SpeedCommand>::value, "SpeedCommand must be destructible");
	static_assert(std::is_copy_constructible<SpeedCommand>::value, "SpeedCommand must be copy constructible");
	static_assert(std::is_copy_assignable<SpeedCommand>::value, "SpeedCommand must be copy assignable");
	static_assert(std::is_move_constructible<SpeedCommand>::value, "SpeedCommand must be move constructible");
	static_assert(std::is_move_assignable<SpeedCommand>::value, "SpeedCommand must be move assignable");
}
