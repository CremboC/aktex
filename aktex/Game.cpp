#include "stdafx.h"

#include "Game.h"
#include "LootBox.h"
#include "Enemy.h"

#include "io.h"
#include "Utils.h"
#include <stdexcept>

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

	State::inst().setScreen(availableScreens["main"]);

	start();
}

Game::~Game()
{}

// contains main loop
void Game::start()
{
	Message *m = State::inst().getMessage();

	string inp = "";
	while (true)
	{
		Vec<string> splitInp = Utils::split(inp, ' ');

		bool specialCmds = false;

		// try doing the move, might be overridden the by screen
		// also catches if user inputs nothing
		try
		{
			screen()->doMove(splitInp.at(0));
		}
		catch (NonOverriddenMoveException *e)
		{
			// not overridden, then might be a default command?
			// if not, prints out available commands
			try
			{
				if (!cmds->exists(splitInp.at(0)))
					throw new IllegalMoveException("");

				specialCmds = cmds->call(splitInp);
			}
			catch (IllegalMoveException *e)
			{

				// TODO: print out default moves as well
				io::print("Move does not exist, try one of the possible commands: ");

				for (string a : screen()->getAllowedMoves())
				{
					io::print(a + " ");
				}

				io::puts();
			}
		}
		catch (std::out_of_range e)
		{
			// just continue, get next input
		}

		if (State::inst().getCurrentState() == GameState::ENDED)
			handleExit();

		if (!specialCmds)
		{
			screen()->act();
		}

		io::print(m->get());

		io::puts();
		io::print("-- ");
		inp = io::multiInput();
		io::puts();

		m->flush();
	}
}

void Game::parseInput(string inp)
{}

// convenience wrapper method for this->state->getCurrentScreen()
Screen *Game::screen()
{
	return State::inst().getCurrentScreen();
}

// handles what happens when the gamestate becomes ENDED
void Game::handleExit()
{
	// TODO: add more stuff that gets done, save game state maybe?
	// confirm exit?
	std::exit(1);
}

// loads all the spawnable prototypes
void Game::loadSpawnables()
{
	Spawnable *lootBox = new LootBox;
	Spawnable *enemy = new Enemy;

	State::inst().registerSpawnable(lootBox);
	State::inst().registerSpawnable(enemy);
}

void Game::loadItems()
{
	State::inst().registerItems(io::readItemsFile());
}