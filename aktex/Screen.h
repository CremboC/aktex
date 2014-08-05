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

public:
	Screen(string name, string text, Vec<string> allowedMoves, EnemyProperties *eProps);
	~Screen();

	string getName();
	string getText();

	Vec<string> getAllowedMoves();
	EnemyProperties *getEnemyProperties();

	bool initialTextShown();

	void defineMoveBehaviour(string move, Func<void> func);
	void doMove(string move);
};
