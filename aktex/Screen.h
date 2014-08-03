#pragma once

#include <functional>

#include "Enemy.h"
#include "EnemyProperties.h"

using std::vector;
using std::string;

using enums::Directions;

using types::HashMap;
using types::Func;

class Screen
{
private:
	vector<string> allowedMoves;
	string name;
	string text;
	EnemyProperties *enemyProperties;
	vector<Directions> directions;

	bool mInitialTextShown;

	HashMap<string, Func<void>> moveBehaviours;

public:
	Screen();
	~Screen();

	Screen *setName(string name);
	Screen *setText(string text);
	Screen *setAllowedMoves(vector<string> allowedMoves);
	Screen *setEnemyProperties(EnemyProperties *eProps);
	Screen *setDirections(vector<Directions> directions);

	string getName();
	string getText();

	vector<string> getAllowedMoves();
	EnemyProperties *getEnemyProperties();

	bool initialTextShown();

	void defineMoveBehaviour(string move, Func<void> func);

	void doMove(string move);
};
