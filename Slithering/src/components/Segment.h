#ifndef _COMP_SEGMENT_H
#define _COMP_SEGMENT_H

namespace app::comp
{
	struct Segment
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
		static void apply(app::Registry & registry, app::Entity const entity, std::optional<app::Entity> parent = std::nullopt, std::optional<app::Entity> child = std::nullopt);
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		std::optional<app::Entity> parent, child;
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

#endif // !_COMP_SEGMENT_H
