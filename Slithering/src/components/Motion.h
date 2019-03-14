#ifndef _COMP_MOTION_H
#define _COMP_MOTION_H

namespace app::comp
{
	struct Motion
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
		static void apply(app::Registry & registry, app::Entity const entity, std::float_t speed = 0.0f, std::optional<std::float_t> direction = std::nullopt);
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::float_t speed;
		std::optional<std::float_t> direction;
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

#endif // !_COMP_MOTION_H
