#pragma once

namespace app::train
{
	class TrainingSet
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		TrainingSet() = default;
		~TrainingSet() = default;

		TrainingSet(TrainingSet const &) = default;
		TrainingSet & operator=(TrainingSet const &) = default;

		TrainingSet(TrainingSet &&) = default;
		TrainingSet & operator=(TrainingSet &&) = default;

	public: // Public Static Functions
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

	static_assert(std::is_default_constructible<TrainingSet>::value, "TrainingSet must be default constructible");
	static_assert(std::is_destructible<TrainingSet>::value, "TrainingSet must be destructible");
	static_assert(std::is_copy_constructible<TrainingSet>::value, "TrainingSet must be copy constructible");
	static_assert(std::is_copy_assignable<TrainingSet>::value, "TrainingSet must be copy assignable");
	static_assert(std::is_move_constructible<TrainingSet>::value, "TrainingSet must be move constructible");
	static_assert(std::is_move_assignable<TrainingSet>::value, "TrainingSet must be move assignable");
}

