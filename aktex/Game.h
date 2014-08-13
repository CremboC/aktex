#pragma once

#include "Screens.h"
#include "Screen.h"
#include "State.h"

#include "DefaultCommands.h"

using std::unordered_map;
using std::string;

using types::HashMap;

class Game
{
private:
	HashMap<string, Screen *> availableScreens;

	Screens *screens;

	DefaultCommands *cmds;

	// convenience wrapper method for this->state->getCurrentScreen()
	Screen *screen();

	// handles what happens when the gamestate becomes ENDED
	void handleExit();

	// loads all the spawnable prototypes
	void loadSpawnables();

	void parseInput(string inp);

public:

	Game();
	~Game();

	// contains main loop
	void start();
};
