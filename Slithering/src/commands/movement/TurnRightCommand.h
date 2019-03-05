#ifndef _TURN_RIGHT_COMMAND_H
#define _TURN_RIGHT_COMMAND_H

#include "TurnCommand.h"

namespace app::com
{
	class TurnRightCommand : public TurnCommand
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		TurnRightCommand(app::Entity entity);
		virtual ~TurnRightCommand() = default;

		TurnRightCommand(TurnRightCommand const &) = default;
		TurnRightCommand & operator=(TurnRightCommand const &) = default;

		TurnRightCommand(TurnRightCommand &&) = default;
		TurnRightCommand & operator=(TurnRightCommand &&) = default;

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

#endif // !_TURN_RIGHT_COMMAND_H
