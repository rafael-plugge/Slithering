#include "stdafx.h"
#include <src/Game.h>

// systems
#include <src/systems/InputSystem.h>
#include <src/systems/RenderSystem.h>

app::Game::Game()
	: m_gameLoop(true)
	, m_registry(app::util::Registry::get())
	, m_updateSystems()
	, m_renderSystems()
	, m_pollEventsSignal()
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
		this->pollEvents();
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
			std::make_unique<sys::InputSystem>(m_keyHandler, m_mouseHandler)
		};

		auto renderSystem = std::make_unique<sys::RenderSystem>();
		m_pollEventsSignal.sink().connect<app::sys::RenderSystem, &app::sys::RenderSystem::pollEvents>(renderSystem.get());
		m_renderSystems = {
			std::move(renderSystem)
		};

		return true;
	}
	catch (std::exception const & e)
	{
		app::Console::writeLine({ "Error: ", e.what() });
		return false;
	}
}

bool app::Game::createEntities()
{
	try
	{
		return true;
	}
	catch (std::exception const & e)
	{
		app::Console::writeLine({ "Error: ", e.what() });
		return false;
	}
}

void app::Game::pollEvents()
{
	m_pollEventsSignal.publish(m_keyHandler, m_mouseHandler);
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
