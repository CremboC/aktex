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

Screen::Screen(string name, string text, Vec<string> allowedMoves, EnemyProperties *eProps)
{
	this->mInitialTextShown = false;
	this->name = name;
	this->text = text;
	this->allowedMoves = allowedMoves;
	this->enemyProperties = eProps;

	generateSpawnables();

	// here for debug m8s
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
			Spawnable *sp = nullptr;
			int rand = 0;

			// if enemyproperties is not set (nullptr), make sure no enemies are
			// present in the spawnable locations
			do
			{
				rand = Utils::random(0, spawnables.size() - 1);

				sp = spawnables[rand];
			} while (spawnables[rand]->realType() == "Enemy" && enemyProperties == nullptr);

			// if is enemy, need to assign its properties defined earlier
			// while constructing the Screen
			if (spawnables[rand]->realType() == "Enemy")
			{
				sp = ((Enemy *) sp)->build(enemyProperties);
			}

			putSpawnable(dir, sp);
		}
	}
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