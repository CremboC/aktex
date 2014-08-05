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
	float likelyHood;
	Vec<Item *> items;

public:
	Enemy();
	Enemy(Enemy *e);
	~Enemy();

	void action();
	string realType();

	Enemy *build(EnemyProperties *props);
};
