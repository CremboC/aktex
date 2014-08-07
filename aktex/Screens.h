#pragma once

#include "Screen.h"
#include "State.h"

using types::HashMap;

class Screens
{
public:
	Screens();
	~Screens();

	// returns the start screen
	Screen *main();

	// the first game screen
	Screen *start();

	// generates randomly a room
	Screen *generateRoom();
};
