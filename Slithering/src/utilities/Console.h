#ifndef _DEBUG_CONSOLE_H
#define _DEBUG_CONSOLE_H

#include <src/utilities/Variant.h>

namespace app
{
	class Console
	{
	public: // Public Usings/Typedefs/Enums
		using SupportedTypes = std::variant<
			  std::string
			, std::stringstream
			, std::uint8_t
			, std::uint16_t
			, std::uint32_t
			, std::uint64_t
			, std::int8_t
			, std::int16_t
			, std::int32_t
			, std::int64_t
			, std::float_t
			, std::double_t
		>;
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
		#ifdef _DEBUG

		/// <summary>
		/// Output to the console the passed text.
		/// 
		/// This function does nothing when _DEBUG is not defined.
		/// </summary>
		/// <param name="message">read-only reference to the text that will be output'd to console.</param>
		static inline void write(SupportedTypes const & message)
		{
			std::visit(app::util::overload{
				  [](std::string const & text) { std::cout << text; }
				, [](std::stringstream const& textStream) { std::cout << textStream.str(); }
				, [](auto const & num) { std::cout << std::to_string(num); }
			}, message);
		}
		static inline void wr(SupportedTypes const & message) { write(message); }

		/// <summary>
		/// Output to the console the collection of text passed.
		/// 
		/// This function does nothing when _DEBUG is not defined.
		/// </summary>
		/// <param name="texts">read-only reference to the collection of text that will be output'd to console.</param>
		static inline void write(std::initializer_list<SupportedTypes> const & messages) { for (auto const & message : messages) { write(message); } }
		static inline void wr(std::initializer_list<SupportedTypes> const & messages) { write(messages); }

		/// <summary>
		/// Output to the console a empty new line.
		///
		/// This function does nothing when _DEBUG is not defined.
		/// </summary>
		static inline void writeLine() { std::cout << std::endl; }
		static inline void wrl() { writeLine(); }

		/// <summary>
		/// Output to the console the passed text, ending with a new line.
		/// 
		/// This function does nothing when _DEBUG is not defined.
		/// </summary>
		/// <param name="text">read-only refernece to the text that will be output'd to console.</param>
		static inline void writeLine(SupportedTypes const & message) { write(message); writeLine(); }
		static inline void wrl(SupportedTypes const & message) { writeLine(message); }

		/// <summary>
		/// Output to the console the collection of text, after which adds a new line.
		/// 
		/// This function does nothing when _DEBUG is not defined.
		/// </summary>
		/// <param name="texts">read-only reference to the collection of text that will be output'd to console.</param>
		static inline void writeLine(std::initializer_list<SupportedTypes> const & messages) { for (auto const & message : messages) { write(message); } writeLine(); }
		static inline void wrl(std::initializer_list<SupportedTypes> const & messages) { writeLine(messages); }

		#else

		static inline void write(SupportedTypes const &) {}
		static inline void wr(SupportedTypes const & message) { write(message); }
		static inline void write(std::initializer_list<SupportedTypes> const &) {}
		static inline void wr(std::initializer_list<SupportedTypes> const & messages) { write(messages); }
		static inline void writeLine() {}
		static inline void wrl() { writeLine(); }
		static inline void writeLine(SupportedTypes const &) {}
		static inline void wrl(SupportedTypes const & message) { writeLine(message); }
		static inline void writeLine(std::initializer_list<SupportedTypes> const &) {}
		static inline void wrl(std::initializer_list<SupportedTypes> const & messages) { writeLine(messages); }

		#endif
	public: // Public Member Functions
	public: // Public Static Variables
		#ifdef _DEBUG
		constexpr static bool DEBUG_MODE = true;
		#else
		constexpr static bool DEBUG_MODE = false;
		#endif

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
	using cout = Console;
}

#endif // !_DEBUG_CONSOLE_H
