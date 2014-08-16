#pragma once

#include "EnemyProperties.h"
#include "Spawnable.h"

using std::string;

using enums::Direction;

using types::HashMap;
using types::Func;
using types::Vec;

class Screen
{
private:
	// private members
	bool isEmpty;

	Vec<string> allowedMoves;

	string name;
	string text;

	EnemyProperties *enemyProperties;

	HashMap<Direction, Spawnable *> spawnableLocations;

	bool mInitialTextShown;

	HashMap<string, Func<void>> moveBehaviours;

	// private methods

	void putSpawnable(Direction d, Spawnable *s);

	void generateSpawnables();

	void parseCommand(string command);

public:
	Screen(string name, string text, Vec<string> allowedMoves, EnemyProperties *eProps, bool isEmpty);
	~Screen();

	string getName() const;
	string getText() const;

	Vec<string> getAllowedMoves() const;
	EnemyProperties *getEnemyProperties() const;

	bool initialTextShown();

	void defineMoveBehaviour(string move, Func<void> func);
	void doMove(string move);

	bool isLocEmpty(Direction d);

	void act();
};
