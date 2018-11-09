#include "stdafx.h"
#include "Game.h"

// systems
#include "systems/RenderSystem.h"

app::Game::Game()
	: m_gameLoop(true)
	, m_registry(app::util::Registry::get())
	, m_updateSystems()
	, m_renderSystems()
{
}

app::Game::~Game()
{
}

int app::Game::run()
{
	using clock = std::chrono::high_resolution_clock;
	constexpr app::time::nanoseconds updateStep =
		app::time::toNanos(std::chrono::duration<double, std::milli>(1 / 60.0 * 1000.0));
	clock::time_point deltaTimePoint = clock::now();
	app::time::nanoseconds elapsedTime = updateStep;
	app::time::nanoseconds deltaRenderStep = app::time::nanoseconds::zero();

	if (!this->init()) { return EXIT_FAILURE; }

	while (m_gameLoop)
	{
		// poll events
		deltaRenderStep =
			(elapsedTime += app::time::toNanos(clock::now() - deltaTimePoint));
		deltaTimePoint = clock::now();
		while (elapsedTime > updateStep)
		{
			this->update(updateStep);
			elapsedTime -= updateStep;
		}
		this->render(deltaRenderStep);
	}

	return EXIT_SUCCESS;
}

bool app::Game::init()
{
	return this->createSystems() && this->createEntities();
}

bool app::Game::createSystems()
{
	try
	{
		m_updateSystems = {
		};

		m_renderSystems = {
			std::make_unique<sys::RenderSystem>()
		};

		return true;
	}
	catch (const std::exception& error)
	{
		app::Console::writeLine(error.what());
		return false;
	}
}

bool app::Game::createEntities()
{
	try
	{
		return true;
	}
	catch (const std::exception& error)
	{
		app::Console::writeLine(error.what());
		return false;
	}
}

void app::Game::pollEvents()
{

}

void app::Game::update(app::time::nanoseconds const & dt)
{
	std::for_each(m_updateSystems.begin(), m_updateSystems.end(),
		[&dt](std::unique_ptr<sys::BaseSystem> & uptrSystem) { uptrSystem->update(dt); });
}

void app::Game::render(app::time::nanoseconds const & dt)
{
	std::for_each(m_renderSystems.begin(), m_renderSystems.end(),
		[&dt](std::unique_ptr<sys::BaseSystem> & uptrSystem) { uptrSystem->update(dt); });
}
