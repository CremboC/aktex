#include "stdafx.h"

#include "Game.h"

#include "Screen.h"
#include "Screens.h"
#include "EnemyProperties.h"
#include "io.h"

using std::string;
using std::pair;

Game::Game()
{
	availableScreens["main"] = Screens::main();

	start(availableScreens["main"]);
}

Game::~Game()
{}

void Game::start(Screen *initialScreen)
{
	while (true)
	{
		io::puts(initialScreen->getText());

		string inp = io::strInput();
	}
}