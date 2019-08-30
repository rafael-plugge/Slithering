#pragma once

namespace app::util
{
	template<std::size_t _Size>
	class Range
	{
		static_assert(_Size > 0, "_Size template argument must not be zero");
	public: // Public Usings/Typedefs/Enums
		using iterator = typename std::array<std::size_t, _Size>::iterator;
		using const_iterator = typename std::array<std::size_t, _Size>::const_iterator;
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		Range() : m_range()
		{
			std::size_t i = 0u;
			for (auto & num : m_range) { num = i++; }
		}

		~Range() = default;

		Range(Range const &) = default;
		Range & operator=(Range const &) = default;

		Range(Range &&) = default;
		Range & operator=(Range &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		iterator begin() { return m_range.begin(); }
		const_iterator begin() const { return m_range.begin(); }
		iterator end() { return m_range.end(); }
		const_iterator end() const { return m_range.end(); }
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
		std::array<std::size_t, _Size> m_range;
	};
}

