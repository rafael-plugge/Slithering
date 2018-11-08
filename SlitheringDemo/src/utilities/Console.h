#ifndef _UTIL_CONSOLE_H
#define _UTIL_CONSOLE_H



namespace app
{
	class Console
	{
	public: // Constructors/Destructor/Assignments
		Console() = delete;
		Console(Console const &) = delete;
		Console(Console &&) = delete;

		~Console() = delete;

		Console & operator=(Console const &) = delete;
		Console & operator=(Console &&) = delete;

	public: // Public Static Functions
		#ifdef _DEBUG

		constexpr static void write(std::string const & text) { std::cout << text; }
		constexpr static void writeLine() { std::cout << std::endl; }
		constexpr static void writeLine(std::string const & text) { std::cout << text << std::endl; }

		#else

		constexpr static void write(std::string const & text) {}
		constexpr static void writeLine() {}
		constexpr static void writeLine(std::string const & text) {}

		#endif
	public: // Public Member Functions
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

#endif // !_UTIL_CONSOLE_H
