#pragma once

#include <functional>

#include "Enemy.h"
#include "EnemyProperties.h"

using std::vector;
using std::string;

class Screen
{
private:
	// a hashmap for strings and stored functions
	typedef std::unordered_map<string, std::function<void()>> sf_hashmap;

	vector<string> allowedMoves;
	string name;
	string text;
	EnemyProperties *enemyProperties;

	sf_hashmap moveBehaviours;

public:
	Screen(string name, string text, vector<string> allowedMoves, EnemyProperties *eProperties);
	~Screen();

	string getName();
	string getText();

	vector<string> getAllowedMoves();

	EnemyProperties *getEnemyProperties();

	void defineMoveBehaviour(string move, std::function<void()> func);

	void doMove(string move);
};