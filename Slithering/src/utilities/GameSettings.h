#pragma once

namespace app
{
	struct Settings
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
		operator std::string() const
		{
			auto text = std::stringstream();
			text << "Game Settings:\n"
				<< " => Player Enabled [" << (this->playerEnabled ? "yes" : "no") << "]\n"
				<< " => FSM Enabled [" << (this->fsmEnabled ? "yes" : "no") << "]\n"
				<< " => AI Enabled [" << (this->aiEnabled ? "yes" : "no") << "]\n"
				<< "";
			return text.str();
		}
	public: // Public Static Variables
	public: // Public Member Variables
		bool playerEnabled;
		bool fsmEnabled;
		bool aiEnabled;
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
