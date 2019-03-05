#include "stdafx.h"
#include "Game.h"

int main(int argc, char** argv)
{
	using clock = std::chrono::high_resolution_clock;
	constexpr app::time::nanoseconds UPDATE_STEP =
		app::time::toNanos(std::chrono::duration<double, std::milli>(1 / 60.0 * 1000.0));
	constexpr auto UPDATE_STEP_SEC = app::time::toSeconds(UPDATE_STEP);
	clock::time_point deltaTimePoint = clock::now();
	app::time::nanoseconds elapsedTime = UPDATE_STEP;
	app::time::nanoseconds deltaRenderStep = app::time::nanoseconds::zero();

	auto game = app::Game();
	if (!game.init()) { return EXIT_FAILURE; }

	while (game.isRunning())
	{
		game.pollEvents();
		deltaRenderStep =
			(elapsedTime += app::time::toNanos(clock::now() - deltaTimePoint));
		deltaTimePoint = clock::now();
		for (; elapsedTime > UPDATE_STEP; elapsedTime -= UPDATE_STEP)
		{
			game.update(UPDATE_STEP_SEC);
		}
		game.render(deltaRenderStep);
	}

	return EXIT_SUCCESS;
}