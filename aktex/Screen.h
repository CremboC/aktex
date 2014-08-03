#pragma once

#include <functional>

#include "EnemyProperties.h"
#include "Spawnable.h"

using std::vector;
using std::string;

using enums::Direction;

using types::HashMap;
using types::Func;

class Screen
{
private:
	vector<string> allowedMoves;
	string name;
	string text;
	EnemyProperties *enemyProperties;

	HashMap<Direction, Spawnable> spawnableLocations;

	bool mInitialTextShown;

	HashMap<string, Func<void>> moveBehaviours;

public:
	Screen();
	~Screen();

	Screen *setName(string name);
	Screen *setText(string text);
	Screen *setAllowedMoves(vector<string> allowedMoves);
	Screen *setEnemyProperties(EnemyProperties *eProps);

	string getName();
	string getText();

	vector<string> getAllowedMoves();
	EnemyProperties *getEnemyProperties();

	bool initialTextShown();

	void defineMoveBehaviour(string move, Func<void> func);
	void doMove(string move);

	void putSpawnable(Direction d, Spawnable s);
};
