#include "stdafx.h"

#include <typeinfo>

#include "Screen.h"
#include "State.h"
#include "Utils.h"
#include "Enemy.h"

#include "io.h"

using exceptions::IllegalMoveException;

using enums::Direction;

using consts::directionsMap;

using types::Vec;

Screen::Screen()
{
	this->mInitialTextShown = false;

	generateSpawnables();

	io::puts("Printing spawnablesLocs: ");

	// initialise spawnables
	for (auto it = spawnableLocations.begin(); it != spawnableLocations.end(); ++it)
	{
		Direction d = it->first;
		Spawnable *s = it->second;

		io::puts("type: " + s->realType());
	}
}

Screen::~Screen()
{}

void Screen::putSpawnable(Direction d, Spawnable *s)
{
	spawnableLocations[d] = s;
}

void Screen::generateSpawnables()
{
	// get all the available, registered spawnables
	Vec<Spawnable *> spawnables = State::getInstance().getSpawnables();

	// initialise spawnables
	for (auto it = directionsMap.begin(); it != directionsMap.end(); ++it)
	{
		Direction dir = it->second;

		// used to determine whether there will be something in this direction
		float lr = Utils::random(0.0f, 1.0f);

		// using the ratio, decide whether to put something into this location
		if (lr > MAX_SPAWN_RATIO - (State::getInstance().getRoomNumber() * SPAWN_RATIO_CHNG))
		{
			// generate a random int which will pick one of the spawnables
			int rand = Utils::random(0, spawnables.size() - 1);

			Spawnable *sp = spawnables[rand];

			if (spawnables[rand]->realType() == "Enemy")
			{
				sp = ((Enemy *) sp)->build(enemyProperties);
			}

			putSpawnable(dir, sp);
		}
	}
}

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

string Screen::getText()
{
	mInitialTextShown = true;
	return text;
}

Vec<string> Screen::getAllowedMoves()
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