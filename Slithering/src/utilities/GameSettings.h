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
				<< " => AI Enabled [" << (this->ai.enabled ? "yes" : "no") << "]\n"
				<< " => AI Reset [" << (this->ai.reset ? "yes" : "no") << "]\n"
				<< " => AI Training Enabled [" << (this->ai.train ? "yes" : "no") << "]\n"
				<< " => AI Training Loops [" << (this->ai.howMany) << "]\n"
				<< "";
			return text.str();
		}
	public: // Public Static Variables
	public: // Public Member Variables
		bool playerEnabled;
		bool fsmEnabled;
		struct
		{
			bool enabled;
			bool train = false;
			bool reset = false;
			long howMany = 0;
		}ai;
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
