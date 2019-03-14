﻿#pragma once

namespace app::com
{
	class BaseCommand
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		BaseCommand();
		~BaseCommand() = default;

		BaseCommand(BaseCommand const & other);
		BaseCommand & operator=(BaseCommand const & other);

		BaseCommand(BaseCommand &&) = default;
		BaseCommand & operator=(BaseCommand &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void execute() const abstract;
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
		app::Registry & m_registry;
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}
