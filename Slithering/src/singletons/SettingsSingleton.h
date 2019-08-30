#pragma once

#include <src/utilities/GameSettings.h>

namespace app::sin
{
	class Settings
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Settings() = delete;
		~Settings() = default;

		Settings(Settings const&) = default;
		Settings& operator=(Settings const&) = default;

		Settings(Settings&&) = default;
		Settings& operator=(Settings&&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		template<typename... Args>
		static app::Settings const& get(Args&&... args)
		{
			if (!s_settings) { s_settings.emplace(std::forward<Args>(args)...); }
			return *s_settings;
		}
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
		static std::optional<app::Settings const> s_settings;
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

