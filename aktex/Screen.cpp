#include "stdafx.h"

#include <typeinfo>

#include "Game.h"
#include "Screen.h"
#include "State.h"
#include "Utils.h"
#include "Enemy.h"

#include "LootBox.h"

using exceptions::NonOverriddenMoveException;

using enums::Direction;

using consts::directionsMap;
using consts::reverseDirectionLookup;

using types::Vec;

Screen::Screen(string name, string text, Vec<string> allowedMoves, EnemyProperties *eProps, bool isEmpty)
{
	this->mInitialTextShown = false;
	this->name = name;
	this->text = text;
	this->allowedMoves = allowedMoves;
	this->enemyProperties = eProps;
	this->isEmpty = isEmpty;

	if (!isEmpty)
	{
		generateSpawnables();
	}
}

Screen::~Screen()
{
	for (auto sp : spawnableLocations)
	{
		if (sp.second != nullptr)
		{
			delete sp.second;
		}
	}
}

void Screen::act()
{
	Player *p = State::inst().getPlayer();
	Message *m = State::inst().getMessage();

	if (p->getPosition() == Direction::C)
	{
		m->append(getText());

		Vec<string> nonEmptyLocations;

		for (auto s : spawnableLocations)
		{
			if (s.second != nullptr)
			{
				string direction = reverseDirectionLookup(s.first);

				if (!visitedLocations[s.first])
				{
					nonEmptyLocations.push_back(direction);
				}
			}
		}

		if (nonEmptyLocations.size() > 0)
		{
			string b = "You see something at ";
			for (string loc : nonEmptyLocations)
			{
				b += loc + ", ";
			}
			b += "\n";

			m->append(b);
		}
	}
	else
	{
		Spawnable *s = spawnableLocations[p->getPosition()];

		if (s != nullptr)
		{
			s->action();
			visitedLocations[p->getPosition()] = true;
		}

		if (s == nullptr)
		{
			p->setPosition(Direction::C);
		}
	}
}

void Screen::generateSpawnables()
{
	// get all the available, registered spawnables
	Vec<Spawnable *> spawnables = State::inst().getSpawnables();

	// initialise spawnables
	for (auto m : directionsMap)
	{
		Direction dir = m.second;

		if (dir == Direction::C)
		{
			continue;
		}

		// used to determine whether there will be something in this direction
		float lr = Utils::random(0.0f, 1.0f);

		// using the ratio, decide whether to put something into this location
		if (lr > MAX_SPAWN_RATIO - (State::inst().getRoomNumber() * SPAWN_RATIO_CHNG))
		{
			// generate a random int which will pick one of the spawnables
			Spawnable *sp = nullptr;

			int randNumber = 0;

			// if enemy properties is not set (nullptr), make sure no enemies are
			// present in the spawnable locations
			do
			{
				randNumber = Utils::random(0, spawnables.size() - 1);

				sp = spawnables[randNumber];
			} while (spawnables[randNumber]->realType() == "Enemy" && enemyProperties == nullptr);

			// if is enemy, need to assign its properties defined earlier
			// while constructing the Screen
			if (spawnables[randNumber]->realType() == "Enemy")
			{
				sp = new Enemy(*enemyProperties);
			}

			if (spawnables[randNumber]->realType() == "LootBox")
			{
				sp = new LootBox;
			}

			putSpawnable(dir, sp);
		}
	}
}

void Screen::putSpawnable(Direction d, Spawnable *s)
{
	visitedLocations[d] = false;
	spawnableLocations[d] = s;
}

string Screen::getText() const
{
	return text;
}

Vec<string> Screen::getAllowedMoves() const
{
	return allowedMoves;
}

EnemyProperties *Screen::getEnemyProperties() const
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
		throw new NonOverriddenMoveException("Move does not exist.");
	}

	// move exists, fetch it and run it
	auto fMove = moveBehaviours[move];

	fMove();
}

bool Screen::isLocEmpty(Direction d)
{
	if (spawnableLocations[d] == nullptr)
	{
		return true;
	}

	return false;
}