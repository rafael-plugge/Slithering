#include "stdafx.h"
#include "ForwardCommand.h"
#include <src/math/Math.h>
// components
#include <src/components/Motion.h>
#include <src/components/Location.h>

app::com::ForwardCommand::ForwardCommand(app::Entity const entity)
	: BaseCommand()
	, m_entity(entity)
{
}

void app::com::ForwardCommand::execute() const
{
	auto view = m_registry.view<comp::Motion, comp::Location>();
	assert(view.contains(m_entity));

	auto const &[motion, location] = view.get<comp::Motion, comp::Location>(m_entity);

	auto const & velocity = math::toVector(motion.direction.value_or(location.orientation)) * motion.speed;
	location.position += velocity;
}
