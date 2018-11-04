#include "stdafx.h"
#include "Game.h"

app::Game::Game()
{
}

app::Game::~Game()
{
}

int app::Game::run()
{
	if (!this->init()) { return EXIT_FAILURE; }

	return EXIT_SUCCESS;
}

bool app::Game::init()
{
	return true;
}

void app::Game::update()
{
}

void app::Game::render()
{
}
