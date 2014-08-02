#pragma once

#include "Screen.h"

class Screens
{
public:
	Screens();
	~Screens();

	// returns the start screen
	static Screen *main();

	// the first game screen
	static Screen *start();
};
