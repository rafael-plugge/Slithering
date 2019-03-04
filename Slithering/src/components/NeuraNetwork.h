#ifndef _COMP_NEURAL_NETWORK_H
#define _COMP_NEURAL_NETWORK_H

namespace app::comp
{
	struct NeuralNetwork
	{
	public: // Public typedefs/usings/enums
		using SampleType = dlib::matrix<double, 5, 2>;
		using Network = dlib::mlp::kernel_1a_c;
	public: // Constructors/Destructor/Assignments
	public: // Public Static Functions
	public: // Public Member Functions
	public: // Public Static Variables
	public: // Public Member Variables
		Network network = Network(5, 0, 0, 3);
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

#endif // !_COMP_NEURAL_NETWORK_H
