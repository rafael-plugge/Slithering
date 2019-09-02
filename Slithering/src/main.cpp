#include "stdafx.h"
#include <src/Game.h>
#include <src/singletons/SettingsSingleton.h>

std::vector<std::string> collectArguments(int argc, char** argv) noexcept;
bool setStartSettings(std::vector<std::string> const & arguments);
bool caseInsensitiveStringEquality(std::string const& left, std::string const& right);
template<typename _Type> void askSetting(std::string const& msg, _Type& setting);
void playerSettings(app::Settings& settings);
void fsmSettings(app::Settings& settings);
void aiSettings(app::Settings& settings);
bool gameStartSetting();
int startGame();

int main(int argc, char** argv)
{
	if (!setStartSettings(collectArguments(argc, argv))) { return EXIT_SUCCESS; }
	return startGame();
}

std::vector<std::string> collectArguments(int argc, char** argv) noexcept
{
	std::vector<std::string> arguments;
	if (argc > 1)
	{
		arguments.reserve(argc - 1);
		for (std::size_t i = 1; i < argc; ++i)
		{
			arguments.emplace_back(argv[i]);
		}
	}
	return std::move(arguments);
}

std::optional<bool> presetSettings(std::vector<std::string> const& arguments, app::Settings& settings)
{
	if (arguments.size() <= 0) { return std::nullopt; }

	if (arguments.size() > 0)
	{
		auto constexpr yesStr = "-y";
		auto constexpr noStr = "-n";

		if (caseInsensitiveStringEquality(arguments.at(0), yesStr)) { settings.playerEnabled = true; }
		if (caseInsensitiveStringEquality(arguments.at(0), noStr)) { settings.playerEnabled = false; }

		if (arguments.size() <= 1) { return std::nullopt; }
		if (caseInsensitiveStringEquality(arguments.at(1), yesStr)) { settings.fsmEnabled = true; }
		if (caseInsensitiveStringEquality(arguments.at(1), noStr)) { settings.fsmEnabled = false; }

		if (arguments.size() <= 2) { return std::nullopt; }
		if (caseInsensitiveStringEquality(arguments.at(2), yesStr)) { settings.ai.enabled = true; }
		if (caseInsensitiveStringEquality(arguments.at(2), noStr)) { settings.ai.enabled = false; }

		if (arguments.size() <= 3) { return std::nullopt; }
		if (caseInsensitiveStringEquality(arguments.at(3), yesStr))
			return true;
		if (caseInsensitiveStringEquality(arguments.at(3), noStr))
			return false;
		return std::nullopt;
	}
}

bool setStartSettings(std::vector<std::string> const& arguments)
{
	auto gameSettings = app::Settings();

	if (auto const presetStart = presetSettings(arguments, gameSettings); presetStart.has_value())
	{
		auto const& settings = app::sin::Settings::get(std::move(gameSettings));
		std::cout << static_cast<std::string>(settings) << std::endl;
		return presetStart.value();
	}

	std::cout <<
		"///////////////////////////////////////\n"
		"////       Startup Settings        ////\n"
		"///////////////////////////////////////\n"
		"\n";

	playerSettings(gameSettings);
	fsmSettings(gameSettings);
	aiSettings(gameSettings);

	auto const& settings = app::sin::Settings::get(std::move(gameSettings));
	std::cout << static_cast<std::string>(settings) << std::endl;

	bool const gameStart = gameStartSetting();

	std::cout << std::endl;
	std::cout <<
		"///////////////////////////////////////\n"
		"///////////////////////////////////////\n"
		"///////////////////////////////////////\n";
	return gameStart;
}

bool caseInsensitiveStringEquality(std::string const& left, std::string const& right)
{
	return std::equal(left.begin(), left.end(),
		right.begin(), right.end(),
		[](char const& l, char const& r) -> bool { return std::tolower(l) == std::tolower(r); }
	);
}

bool stringIsOnlyDigits(std::string const& str)
{
	return !str.empty() && str.find_first_not_of("0123456789") == std::string::npos;
}

std::optional<long const> stringToLong(std::string const& str)
{
	auto iss = std::istringstream(str);
	long result;
	iss >> result;
	if (iss.fail()) { return std::nullopt; }
	return result;

}

template<typename _Type>
void askSetting(std::string const& msg, _Type& setting)
{
	std::optional<_Type const> answer;
	do
	{
		std::cout << msg;
		std::string input;
		std::cin >> input;
		if constexpr (std::is_same<bool, _Type>::value)
		{
			if (caseInsensitiveStringEquality(input, "y")) { answer.emplace(true); }
			if (caseInsensitiveStringEquality(input, "n")) { answer.emplace(false); }
		}
		else if constexpr (std::is_same<long, _Type>::value)
		{
			if (stringIsOnlyDigits(input))
				if (auto const result = stringToLong(input); result.has_value())
					answer.emplace(result.value());
		}
	} while (!answer.has_value());
	setting = answer.value();
	std::cout << std::endl;
}

void playerSettings(app::Settings& settings)
{
	askSetting("Enable player [y/n]: ", settings.playerEnabled);
}

void fsmSettings(app::Settings& settings)
{
	askSetting("Enable FSM [y/n]: ", settings.fsmEnabled);
}

void aiSettings(app::Settings& settings)
{
	askSetting("Enable AI [y/n]: ", settings.ai.enabled);
	if (!settings.ai.enabled) { return; }
	askSetting("Train Ai [y/n]: ", settings.ai.train);
	askSetting("Reset Ai [y/n]: ", settings.ai.reset);
	if (!settings.ai.train) { return; }
	askSetting("How many training loops: ", settings.ai.howMany);
}

bool gameStartSetting()
{
	std::optional<bool> startTheGame;
	do
	{
		std::cout << "Start Game [y/n]: ";
		std::string input;
		std::cin >> input;
		if (caseInsensitiveStringEquality(input, "y")) { startTheGame.emplace(true); }
		if (caseInsensitiveStringEquality(input, "n")) { startTheGame.emplace(false); }
	} while (!startTheGame.has_value());

	return startTheGame.value();
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

	game.deinit();

	return EXIT_SUCCESS;
}