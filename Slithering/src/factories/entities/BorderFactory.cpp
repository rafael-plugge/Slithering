#include "stdafx.h"
#include <src/factories/entities/BorderFactory.h>

app::fact::ent::BorderFactory::BorderFactory(Parameters & params)
	: ImageFactory(params.imageFactoryParams)
	, m_params(params)
	, m_imageParams(params.imageFactoryParams)
{
}

app::Entity const app::fact::ent::BorderFactory::create()
{
	return ImageFactory::create();
}
