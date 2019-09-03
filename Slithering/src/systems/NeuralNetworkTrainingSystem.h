#pragma once

#include <src/systems/BaseSystem.h>
#include <src/utilities/NeuralNetworkTypes.h>

namespace app::sys
{
	class NeuralNetworkTrainingSystem : public BaseSystem
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		enum class CommandDirection
		{
			Left, Right, Straight
		};
		struct TrainingSet
		{
			struct
			{
				math::Vector2f aiLocation;
				std::float_t aiOrientation;
				math::Vector2f foodLocation;

				operator nn::InputData() const
				{
					auto data = nn::InputData();
					data = aiLocation.x, aiLocation.y
						, aiOrientation
						, foodLocation.x, foodLocation.y;
					return data;
				}
			}input;
			struct
			{
				nn::Type turnLeft;
				nn::Type turnRight;
				nn::Type dontTurn;

				operator nn::OutputData() const
				{
					auto data = nn::OutputData();
					data = turnLeft
						, turnRight
						, dontTurn;
					return data;
				}
			}output;
		};
	public: // Constructors/Destructor/Assignments
		NeuralNetworkTrainingSystem(bool & keepTraining);
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
		CommandDirection getCorrectDirection(math::Vector2f const& position, float const& dir, math::Vector2f const& foodLocation);
		std::array<nn::Type, 3> generateOutput(CommandDirection const& dir);
		TrainingSet readyData(math::Vector2f const& pos, float const& dir, math::Vector2f const& foodLocation, std::array<nn::Type, 3> const& response);
		void positionDataLoop(nn::Network& nn, math::Vector2f const& foodLocation);
		void foodDataLoop(nn::Network& nn);
	private: // Private Static Variables
	private: // Private Member Variables
		bool& m_keepTraining;
		std::optional<bool const> m_train;
		long m_counter;
		math::Vector2f m_trainingEdge;
		float m_positionSkipRate;
		math::Vector2f m_foodRegion;
		float m_foodSkipRate;
		float m_angleSkipRate;
	};

	static_assert(std::is_destructible<NeuralNetworkTrainingSystem>::value, "NeuralNetworkTrainingSystem must be destructible");
	static_assert(std::is_copy_constructible<NeuralNetworkTrainingSystem>::value, "NeuralNetworkTrainingSystem must be copy constructible");
	static_assert(std::is_move_constructible<NeuralNetworkTrainingSystem>::value, "NeuralNetworkTrainingSystem must be move constructible");
}
