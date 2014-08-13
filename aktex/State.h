#pragma once

#include "Player.h"
#include "Screen.h"

using enums::GameState;

using types::Vec;

// singleton
class State
{
private:
	Player *player;
	Screen *currentScreen;

	int roomNumber = 0;
	GameState currentState;

	Vec<Spawnable *> spawnables;

	State()
	{
		this->player = new Player;
		this->currentState = GameState::RUNNING;
	}

	State(State const&);
	void operator=(State const&);

public:

	static State& getInstance()
	{
		static State instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	}

	Player *getPlayer();
	Screen *getCurrentScreen();
	int getRoomNumber();
	GameState getCurrentState();
	Vec<Spawnable *> getSpawnables();

	void setState(GameState newState);
	void setScreen(Screen *screen);

	void registerSpawnable(Spawnable *spawnable);

	void registerSpawnables(Vec<Spawnable *> spawnable);
};
