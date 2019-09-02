#pragma once

#include "BaseSystem.h"

namespace app::sys
{
	class NeuralNetworkSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
	public: // Constructors/Destructor/Assignments
		NeuralNetworkSystem() = default;
		virtual ~NeuralNetworkSystem() = default;

		NeuralNetworkSystem(NeuralNetworkSystem const &) = default;
		NeuralNetworkSystem & operator=(NeuralNetworkSystem const &) = default;

		NeuralNetworkSystem(NeuralNetworkSystem &&) = default;
		NeuralNetworkSystem & operator=(NeuralNetworkSystem &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual void init() final override;
		virtual void update(app::time::seconds const & dt) final override;
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

	static_assert(std::is_default_constructible<NeuralNetworkSystem>::value, "NeuralNetworkSystem must be default constructible");
	static_assert(std::is_destructible<NeuralNetworkSystem>::value, "NeuralNetworkSystem must be destructible");
	static_assert(std::is_copy_constructible<NeuralNetworkSystem>::value, "NeuralNetworkSystem must be copy constructible");
	static_assert(std::is_copy_assignable<NeuralNetworkSystem>::value, "NeuralNetworkSystem must be copy assignable");
	static_assert(std::is_move_constructible<NeuralNetworkSystem>::value, "NeuralNetworkSystem must be move constructible");
	static_assert(std::is_move_assignable<NeuralNetworkSystem>::value, "NeuralNetworkSystem must be move assignable");
}
