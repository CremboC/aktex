#pragma once

#include <vector>

#include "Enemy.h"

using std::vector;
using std::string;

class Screen
{
private:
	vector<string> allowedMoves;
	string name;
	string text;
	EnemyProperties *enemyProperties;

public:
	Screen(string name, string text, vector<string> allowedMoves, EnemyProperties *eProperties);
	~Screen();

	string getName();
	string getText();

	vector<string> getAllowedMoves();

	EnemyProperties *getEnemyProperties();
};
