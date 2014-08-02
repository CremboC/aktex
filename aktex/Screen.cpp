#include "stdafx.h"

#include "Screen.h"

using exceptions::IllegalMoveException;

Screen::Screen(string name, string text, vector<string> allowedMoves, EnemyProperties *properties)
{
	this->name = name;
	this->text = text;
	this->allowedMoves = allowedMoves;
	this->enemyProperties = properties;
	this->mInitialTextShown = false;
}

Screen::~Screen()
{}

string Screen::getName()
{
	return this->name;
}

string Screen::getText()
{
	mInitialTextShown = true;
	return text;
}

vector<string> Screen::getAllowedMoves()
{
	return allowedMoves;
}

EnemyProperties *Screen::getEnemyProperties()
{
	return enemyProperties;
}

bool Screen::initialTextShown()
{
	return mInitialTextShown;
}

void Screen::defineMoveBehaviour(string move, std::function<void()> func)
{
	moveBehaviours[move] = func;
}

void Screen::doMove(string move)
{
	// check if move exists first
	auto it = moveBehaviours.find(move);

	if (it == moveBehaviours.end())
	{
		throw new IllegalMoveException("Move does not exist.");
	}

	// move exists, fetch it and run it
	auto fMove = moveBehaviours[move];

	fMove();
}