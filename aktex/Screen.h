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
	Screen();
	~Screen();

	Screen *setName(string name);
	Screen *setText(string text);
	Screen *setAllowedMoves(Vec<string> allowedMoves);
	Screen *setEnemyProperties(EnemyProperties *eProps);

	string getName();
	string getText();

	Vec<string> getAllowedMoves();
	EnemyProperties *getEnemyProperties();

	bool initialTextShown();

	void defineMoveBehaviour(string move, Func<void> func);
	void doMove(string move);
};
