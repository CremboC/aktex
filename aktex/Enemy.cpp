#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{}

Enemy::Enemy(Enemy *e)
{}

Enemy::~Enemy()
{}

void Enemy::action()
{}

string Enemy::realType()
{
	return "Enemy";
}

Enemy *Enemy::build(EnemyProperties *props)
{
	Enemy *e = new Enemy(this);
	e->numOfDrops = props->getNumberOfPossibleDrops();
	e->likelyHood = props->getDropLikelyHood();

	return e;
}