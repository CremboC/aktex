#pragma once

#include "Item.h"

using std::pair;
using std::vector;

class EnemyProperties
{
public:
	EnemyProperties();
	~EnemyProperties();

	// set the hp range of the enemies
	EnemyProperties *hpRange(pair<int, int> range);

	// how many drops can be droped by a single enemy
	EnemyProperties *possibleDrops(int numberOfPossibleDrops);

	// how likely it is for a drop to occur, per "possibleDrop"
	EnemyProperties *dropLikelyhood(float dropLikelyhood);

	// what items the enemy can drop
	EnemyProperties *items(vector<Item *> items);

private:
	pair<int, int> mHpRange;
	float mDropLikelyhood;
	int numberOfPossibleDrops;
	vector<Item *> mItems;
};
