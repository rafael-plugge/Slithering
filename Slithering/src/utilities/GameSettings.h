﻿#pragma once

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
				<< " => Player Enabled [" << (this->playerEnabled ? "y" : "n") << "]"
				<< "";
			return text.str();
		}
	public: // Public Static Variables
	public: // Public Member Variables
		bool playerEnabled = true;
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