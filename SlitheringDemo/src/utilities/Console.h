#ifndef _UTIL_CONSOLE_H
#define _UTIL_CONSOLE_H



namespace app
{
	class Console
	{
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
		#ifdef _DEBUG

		inline static void write(std::string const & text) { std::cout << text; }
		inline static void writeLine() { std::cout << std::endl; }
		inline static void writeLine(std::string const & text) { std::cout << text << std::endl; }

		#else

		inline static void write(std::string const & text) {}
		inline static void writeLine() {}
		inline static void writeLine(std::string const & text) {}

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
		Console() = default;
		Console(Console const &) = default;
		Console(Console &&) = default;

		~Console() = default;

		Console & operator=(Console const &) = default;
		Console & operator=(Console &&) = default;
	};
}

#endif // !_UTIL_CONSOLE_H
