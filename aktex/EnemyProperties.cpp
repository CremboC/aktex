#include "stdafx.h"
#include "EnemyProperties.h"

using std::pair;

EnemyProperties::EnemyProperties()
{
	mDropLikelyhood = 0.0f;
	numberOfPossibleDrops = 0;
}

EnemyProperties::~EnemyProperties()
{}

// set the hp range of the enemies
EnemyProperties *EnemyProperties::hpRange(pair<int, int> range)
{
	this->mHpRange = range;
	return this;
}

// how many drops can be droped by a single enemy
EnemyProperties *EnemyProperties::possibleDrops(int numberOfPossibleDrops)
{
	this->numberOfPossibleDrops = numberOfPossibleDrops;
	return this;
}

// how likely it is for a drop to occur, per "possibleDrop"
EnemyProperties *EnemyProperties::dropLikelyhood(float dropLikelyhood)
{
	this->mDropLikelyhood = dropLikelyhood;
	return this;
}

// what items the enemy can drop
EnemyProperties *EnemyProperties::items(vector<Item *> items)
{
	this->mItems = items;
	return this;
}

const float EnemyProperties::getDropLikelyHood()
{
	return mDropLikelyhood;
}

const int EnemyProperties::getNumberOfPossibleDrops()
{
	return numberOfPossibleDrops;
}

const pair<int, int> EnemyProperties::getHpRange()
{
	return mHpRange;
}

Vec<Item *> EnemyProperties::getItems()
{
	return mItems;
}