#ifndef _DEFAULT_COMMAND_H
#define _DEFAULT_COMMAND_H

#include "BaseCommand.h"

namespace app::com
{
	class DefaultCommand : public BaseCommand
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		DefaultCommand() = default;
		virtual ~DefaultCommand() = default;

		DefaultCommand(DefaultCommand const &) = default;
		DefaultCommand & operator=(DefaultCommand const &) = default;

		DefaultCommand(DefaultCommand &&) = default;
		DefaultCommand & operator=(DefaultCommand &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void execute() const override {}
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

#endif // !_DEFAULT_COMMAND_H
