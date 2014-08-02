#pragma once

#include <functional>

#include "Enemy.h"
#include "EnemyProperties.h"

using std::vector;
using std::string;
using std::unordered_map;

class Screen
{
private:
	// a hashmap for strings and stored functions
	typedef unordered_map<string, std::function<void(int)>> sf_hashmap;

	typedef unordered_map<string, Screen *> ss_hashmap;

	vector<string> allowedMoves;
	string name;
	string text;
	EnemyProperties *enemyProperties;

	sf_hashmap defineMoveBehaviours;

public:
	Screen(string name, string text, vector<string> allowedMoves, EnemyProperties *eProperties);
	~Screen();

	string getName();
	string getText();

	vector<string> getAllowedMoves();

	EnemyProperties *getEnemyProperties();

	template<typename F>
	void defineMoveBehaviour(string move, F func);
};
