#include "stdafx.h"
#include "Game.h"
#include <src/singletons/SettingsSingleton.h>

bool setStartSettings();
bool caseInsensitiveStringEquality(std::string const& left, std::string const& right);
int startGame();

int main(int argc, char** argv)
{
	if (!setStartSettings()) { return EXIT_SUCCESS; }
	return startGame();
}

bool setStartSettings()
{
	auto gameSettings = app::Settings();

	std::cout <<
		"///////////////////////////////////////\n"
		"////       Startup Settings        ////\n"
		"///////////////////////////////////////\n"
		"\n";

	// Enable player setting
	{
		std::optional<bool const> enablePlayer;
		do
		{
			std::cout << "Enable player [y/n]: ";
			std::string input;
			std::cin >> input;
			if (caseInsensitiveStringEquality(input, "y")) { enablePlayer.emplace(true); }
			if (caseInsensitiveStringEquality(input, "n")) { enablePlayer.emplace(false); }
		} while (!enablePlayer.has_value());
		gameSettings.playerEnabled = enablePlayer.value();
		std::cout << std::endl;
	}


	auto const& settings = app::sin::Settings::get(std::move(gameSettings));
	std::cout << static_cast<std::string>(settings) << std::endl;

	std::optional<bool> startTheGame;
	do
	{
		std::cout << "Start Game [y/n]: ";
		std::string input;
		std::cin >> input;
		if (caseInsensitiveStringEquality(input, "y")) { startTheGame.emplace(true); }
		if (caseInsensitiveStringEquality(input, "n")) { startTheGame.emplace(false); }
	} while (!startTheGame.has_value());

	std::cout << std::endl;
	std::cout <<
		"///////////////////////////////////////\n"
		"///////////////////////////////////////\n"
		"///////////////////////////////////////\n";
	return startTheGame.value();
}

bool caseInsensitiveStringEquality(std::string const& left, std::string const& right)
{
	return std::equal(left.begin(), left.end(),
		right.begin(), right.end(),
		[](char const& l, char const& r) -> bool { return std::tolower(l) == std::tolower(r); }
	);
}

int startGame()
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