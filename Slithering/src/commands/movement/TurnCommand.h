#ifndef _TURN_COMMAND_H
#define _TURN_COMMAND_H

#include "../base/BaseCommand.h"

namespace app::com
{
	class TurnCommand : public BaseCommand
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		TurnCommand(app::Entity entity);
		virtual ~TurnCommand() = default;

		TurnCommand(TurnCommand const &) = default;
		TurnCommand & operator=(TurnCommand const &) = default;

		TurnCommand(TurnCommand &&) = default;
		TurnCommand & operator=(TurnCommand &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
		constexpr static float TURN_RATE = 2.0f;
	protected: // Protected Member Variables
		app::Entity const m_entity;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_TURN_COMMAND_H
