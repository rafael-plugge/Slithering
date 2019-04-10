#ifndef _SEGMENT_FACTORY_H
#define _SEGMENT_FACTORY_H

#include <src/factories/entities/ImageFactory.h>
#include <src/parameters/factories/entities/SegmentFactoryParameters.h>

namespace app::fact::ent
{
	class SegmentFactory : public ImageFactory
	{
	public: // Public Usings/Typedefs/Enums
	protected: // Protected Usings/Typedefs/Enums
	private: // Private Usings/Typedefs/Enums
		using Parameters = par::fact::ent::SegmentFactoryParameters;
	public: // Constructors/Destructor/Assignments
		SegmentFactory(Parameters & params);
		virtual ~SegmentFactory() = default;

		SegmentFactory(SegmentFactory const &) = default;
		SegmentFactory & operator=(SegmentFactory const &) = default;

		SegmentFactory(SegmentFactory &&) = default;
		SegmentFactory & operator=(SegmentFactory &&) = default;

	public: // Public Static Functions
	public: // Public Member Functions
		virtual app::Entity const create() final override;
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
		Parameters const & m_params;
	};
}

#endif // !_SEGMENT_FACTORY_H
