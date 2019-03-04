#ifndef _MOVE_COMMAND_H
#define _MOVE_COMMAND_H

#include "base/BaseCommand.h"

namespace app::com
{
	class MoveCommand : public BaseCommand
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		MoveCommand(app::Entity entity, bool moveRight);
		virtual ~MoveCommand() = default;

		MoveCommand(MoveCommand const &) = default;
		MoveCommand & operator=(MoveCommand const &) = default;

		MoveCommand(MoveCommand &&) = default;
		MoveCommand & operator=(MoveCommand &&) = default;

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
		constexpr static std::float_t s_MOVE_AMOUNT = 10.0f;
	private: // Private Member Variables
		app::Entity const m_entity;
		bool const m_moveRight;
	};
}

#endif // !_MOVE_COMMAND_H
