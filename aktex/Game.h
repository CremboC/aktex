#pragma once

#include "Screens.h"
#include "Screen.h"
#include "State.h"

using std::unordered_map;
using std::string;

class Game
{
private:
	typedef unordered_map<string, Screen *> ss_hashmap;

	ss_hashmap availableScreens;

	State *state;
	Screens *screens;

	// convenience wrapper method for this->state->getCurrentScreen()
	Screen *screen();

	// handles what happens when the gamestate becomes ENDED
	void handleExit();

public:
	Game();
	~Game();

	// contains main loop
	void start();
};
