#pragma once

#include "../base/BaseCommand.h"

namespace app::com
{
	class ForwardCommand : public BaseCommand
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		ForwardCommand(app::Entity const entity);
		virtual ~ForwardCommand() = default;

		ForwardCommand(ForwardCommand const &) = default;
		ForwardCommand & operator=(ForwardCommand const &) = default;

		ForwardCommand(ForwardCommand &&) = default;
		ForwardCommand & operator=(ForwardCommand &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void execute() const final override;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		app::Entity m_entity;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	static_assert(std::is_default_constructible<ForwardCommand>::value == false, "ForwardCommand cannot be default constructible");
	static_assert(std::is_destructible<ForwardCommand>::value, "ForwardCommand must be destructible");
	static_assert(std::is_copy_constructible<ForwardCommand>::value, "ForwardCommand must be copy constructible");
	static_assert(std::is_copy_assignable<ForwardCommand>::value, "ForwardCommand must be copy assignable");
	static_assert(std::is_move_constructible<ForwardCommand>::value, "ForwardCommand must be move constructible");
	static_assert(std::is_move_assignable<ForwardCommand>::value, "ForwardCommand must be move assignable");
}
