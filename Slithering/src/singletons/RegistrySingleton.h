#ifndef _UTIL_REGISTRY_H
#define _UTIL_REGISTRY_H

namespace app::sin
{
	class Registry
	{
	public: // Constructors/Destructor/Assignments
		Registry() = delete;
		virtual ~Registry() = delete;

		Registry(Registry const &) = delete;
		Registry(Registry &&) = delete;

		Registry & operator=(Registry const &) = delete;
		Registry & operator=(Registry &&) = delete;

	public: // Public Static Functions
		static app::Registry & get();
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
		static std::unique_ptr<app::Registry> s_uptrRegistry;
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};
}

#endif // !_UTIL_REGISTRY_H
