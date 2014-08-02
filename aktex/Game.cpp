#include "stdafx.h"

#include "Game.h"

#include "io.h"

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
		if (!screen()->initialTextShown())
			io::puts(screen()->getText());

		string inp = io::strInput();

		try
		{
			screen()->doMove(inp);
		}
		catch (exceptions::IllegalMoveException *e)
		{
			io::print("Move does not exist, try one of the possible commands: ");

			for (auto a : screen()->getAllowedMoves())
			{
				io::print(a + " ");
			}

			io::puts("");
		}

		if (state->getCurrentState() == GameState::ENDED)
			handleExit();
	}
}

// convenience wrapper method for this->state->getCurrentScreen()
Screen *Game::screen()
{
	return this->state->getCurrentScreen();
}

// handles what happens when the gamestate becomes ENDED
void Game::handleExit()
{
	// TODO: add more stuff that gets done, save game state maybe?
	std::exit(1);
}