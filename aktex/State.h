#pragma once

#include "Player.h"
#include "Screen.h"

using enums::GameState;

using types::Vec;

class State
{
private:
	Player *player;
	Screen *currentScreen;

	GameState currentState;

	Vec<Spawnable *> spawnables;

public:
	State();
	~State();

	Player *getPlayer();
	Screen *getCurrentScreen();
	GameState getCurrentState();
	Vec<Spawnable *> getSpawnables();

	void setState(GameState newState);
	void setScreen(Screen *screen);

	void registerSpawnable(Spawnable *spawnable);

	template<class... T>
	void registerSpawnables(T *... args);
};
