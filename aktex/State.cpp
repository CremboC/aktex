#include "stdafx.h"

#include <cstdarg>

#include "State.h"

#include "io.h"

State::State()
{
	this->player = new Player;
	this->currentState = GameState::RUNNING;
}

State::~State()
{}

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

void State::setState(GameState newState)
{
	this->currentState = newState;
}

void State::setScreen(Screen *screen)
{
	this->currentScreen = screen;
}

void State::registerSpawnable(Spawnable *spawnable)
{
	spawnables.push_back(spawnable);
}

template<class... T>
void State::registerSpawnables(T *... args)
{
	io::puts(sizeof...(args));

	spawnables.push_back(spawnable);
}