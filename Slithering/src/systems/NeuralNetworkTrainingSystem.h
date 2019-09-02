#pragma once

#include <src/systems/BaseSystem.h>

namespace app::sys
{
	class NeuralNetworkTrainingSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		NeuralNetworkTrainingSystem(bool & signalEnd);
		virtual ~NeuralNetworkTrainingSystem() = default;

		NeuralNetworkTrainingSystem(NeuralNetworkTrainingSystem const&) = default;
		NeuralNetworkTrainingSystem& operator=(NeuralNetworkTrainingSystem const&) = default;

		NeuralNetworkTrainingSystem(NeuralNetworkTrainingSystem&&) = default;
		NeuralNetworkTrainingSystem& operator=(NeuralNetworkTrainingSystem&&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void init() final override;
		virtual void update(app::time::seconds const& dt) final override;
		void deinit();
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
		bool& m_signalEnd;
		std::optional<bool const> m_train;
		long m_counter;
	};

	static_assert(std::is_destructible<NeuralNetworkTrainingSystem>::value, "NeuralNetworkTrainingSystem must be destructible");
	static_assert(std::is_copy_constructible<NeuralNetworkTrainingSystem>::value, "NeuralNetworkTrainingSystem must be copy constructible");
	static_assert(std::is_move_constructible<NeuralNetworkTrainingSystem>::value, "NeuralNetworkTrainingSystem must be move constructible");
}
