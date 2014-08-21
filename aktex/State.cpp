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

void State::registerSpawnables(Vec<Spawnable *> spawnablesToRegister)
{
	for (Spawnable *i : spawnablesToRegister)
	{
		spawnables.push_back(i);
	}
}

void State::registerItems(Vec<Item *> itemsToRegister)
{
	for (Item *i : itemsToRegister)
	{
		items.push_back(i);
	}
}

Vec<Item *> State::getItems()
{
	return items;
}

Enemy *State::getCurrentEnemy() const
{
	return currentEnemy;
}

void State::setCurrentEnemy(Enemy *e)
{
	this->currentEnemy = e;
}

Message *State::getMessage()
{
	return message;
}