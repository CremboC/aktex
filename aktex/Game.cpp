#include "stdafx.h"

#include "Game.h"

#include "Screen.h"
#include "Screens.h"
#include "EnemyProperties.h"
#include "io.h"

#include "State.h"

using std::string;
using std::pair;

Game::Game()
{
	this->state = new State;
	this->screens = new Screens(state);

	availableScreens["main"] = screens->main();

	state->setScreen(availableScreens["main"]);

	start();
}

Game::~Game()
{}

// contains main loop
void Game::start()
{
	while (true)
	{
		io::puts(screen()->getText());

		screen()->doMove("exit");

		if (state->getCurrentState() == GameState::ENDED)
		{
			io::puts("ENDED!");
		}

		string inp = io::strInput();
	}
}

// convenience wrapper method for this->state->getCurrentScreen()
Screen *Game::screen()
{
	return this->state->getCurrentScreen();
}