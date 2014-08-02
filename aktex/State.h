#pragma once

#include "Player.h"

using enums::GameState;

class State
{
private:
	Player *player;
	Screen *currentScreen;

	GameState currentState;

public:
	State();
	~State();

	Player *getPlayer();
	Screen *getCurrentScreen();
	GameState getCurrentState();

	void setState(GameState newState);
	void setScreen(Screen *screen);
};
