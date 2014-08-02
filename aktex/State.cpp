#include "stdafx.h"

#include "State.h"

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