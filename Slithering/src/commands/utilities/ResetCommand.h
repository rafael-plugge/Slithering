#pragma once

#include <src/commands/base/BaseCommand.h>

namespace app::com
{
	class ResetCommand : public BaseCommand
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		ResetCommand(app::Entity const targetEntity, math::Vector2f const & resetPosition);
		virtual ~ResetCommand() = default;

		ResetCommand(ResetCommand const &) = default;
		ResetCommand & operator=(ResetCommand const &) = default;

		ResetCommand(ResetCommand &&) = default;
		ResetCommand & operator=(ResetCommand &&) = default;

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
		math::Vector2f m_resetPosition;
	};

	static_assert(std::is_destructible<ResetCommand>::value, "ResetCommand must be destructible");
	static_assert(std::is_copy_constructible<ResetCommand>::value, "ResetCommand must be copy constructible");
	static_assert(std::is_copy_assignable<ResetCommand>::value, "ResetCommand must be copy assignable");
	static_assert(std::is_move_constructible<ResetCommand>::value, "ResetCommand must be move constructible");
	static_assert(std::is_move_assignable<ResetCommand>::value, "ResetCommand must be move assignable");
}
