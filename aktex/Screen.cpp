#include "stdafx.h"

#include "Screen.h"

using exceptions::IllegalMoveException;

Screen::Screen()
{
	this->mInitialTextShown = false;
}

Screen::~Screen()
{}

Screen *Screen::setName(string name)
{
	this->name = name;
	return this;
}

Screen *Screen::setText(string text)
{
	this->text = text;
	return this;
}

Screen *Screen::setAllowedMoves(vector<string> allowedMoves)
{
	this->allowedMoves = allowedMoves;
	return this;
}

Screen *Screen::setEnemyProperties(EnemyProperties *eProps)
{
	this->enemyProperties = eProps;
	return this;
}

Screen *Screen::setDirections(vector<Directions> directions)
{
	this->directions = directions;
	return this;
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

void Screen::defineMoveBehaviour(string move, Func<void> func)
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