#pragma once

#include "Entity.h"
#include "Spawnable.h"
#include "Item.h"

#include "EnemyProperties.h"

using types::Vec;

class Enemy
	: public Entity, public Spawnable
{
private:
	int numOfDrops;
	float likelyhood;
	Vec<Item *> items;

	bool defeated = false;

public:
	Enemy();
	Enemy(EnemyProperties &props);
	~Enemy();

	void action();
	string realType();
};
