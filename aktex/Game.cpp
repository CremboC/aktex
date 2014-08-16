#include "stdafx.h"

#include "Game.h"
#include "LootBox.h"
#include "Enemy.h"

#include "io.h"
#include "Utils.h"

using std::string;
using std::pair;

using types::Vec;

using exceptions::IllegalMoveException;
using exceptions::NonOverriddenMoveException;

Game::Game()
{
	cmds = new DefaultCommands;

	loadSpawnables();
	loadItems();

	availableScreens["main"] = screens->main();

	State::getInstance().setScreen(availableScreens["main"]);

	start();
}

Game::~Game()
{}

// contains main loop
void Game::start()
{
	while (true)
	{
		screen()->act();

		string inp = io::multiInput();
		Vec<string> splitInp = Utils::split(inp, ' ');
		io::puts();

		try
		{
			screen()->doMove(splitInp[0]);
		}
		catch (NonOverriddenMoveException *e)
		{
			try
			{
				if (!cmds->exists(splitInp[0]))
					throw new IllegalMoveException("");

				cmds->call(splitInp);
			}
			catch (IllegalMoveException *e)
			{

				io::print("Move does not exist, try one of the possible commands: ");

				for (auto a : screen()->getAllowedMoves())
				{
					io::print(a + " ");
				}

				io::puts();
			}
		}

		if (State::getInstance().getCurrentState() == GameState::ENDED)
			handleExit();
	}
}

void Game::parseInput(string inp)
{}

// convenience wrapper method for this->state->getCurrentScreen()
Screen *Game::screen()
{
	return State::getInstance().getCurrentScreen();
}

// handles what happens when the gamestate becomes ENDED
void Game::handleExit()
{
	// TODO: add more stuff that gets done, save game state maybe?
	std::exit(1);
}

// loads all the spawnable prototypes
void Game::loadSpawnables()
{
	Spawnable *lootBox = new LootBox;
	Spawnable *enemy = new Enemy;

	State::getInstance().registerSpawnable(lootBox);
	State::getInstance().registerSpawnable(enemy);
}

void Game::loadItems()
{
	State::getInstance().registerItems(io::readItemsFile());
}
