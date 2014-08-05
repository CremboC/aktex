#include "stdafx.h"

#include "State.h"

Player *State::getPlayer()
{
	return player;
}

Screen *State::getCurrentScreen()
{
	return currentScreen;
}

GameState State::getCurrentState()
{
	return currentState;
}

Vec<Spawnable *> State::getSpawnables()
{
	return spawnables;
}

int State::getRoomNumber()
{
	return roomNumber;
}

void State::setState(GameState newState)
{
	this->currentState = newState;
}

void State::setScreen(Screen *screen)
{
	this->currentScreen = screen;
	roomNumber++;
}

void State::registerSpawnable(Spawnable *spawnable)
{
	spawnables.push_back(spawnable);
}

void State::registerSpawnables(Vec<Spawnable *> spawnables)
{
	for (auto i : spawnables)
	{
		spawnables.push_back(i);
	}
}