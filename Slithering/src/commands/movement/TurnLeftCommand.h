#ifndef _TURN_LEFT_COMMAND_H
#define _TURN_LEFT_COMMAND_H

#include "TurnCommand.h"

namespace app::com
{
	class TurnLeftCommand : public TurnCommand
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		TurnLeftCommand(app::Entity entity);
		virtual ~TurnLeftCommand() = default;

		TurnLeftCommand(TurnLeftCommand const &) = default;
		TurnLeftCommand & operator=(TurnLeftCommand const &) = default;

		TurnLeftCommand(TurnLeftCommand &&) = default;
		TurnLeftCommand & operator=(TurnLeftCommand &&) = default;

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
	};
}

#endif // !_TURN_LEFT_COMMAND_H
