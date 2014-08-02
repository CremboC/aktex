#pragma once

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
