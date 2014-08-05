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

	e->setNumOfDrops(props->getNumberOfPossibleDrops());
	e->setLikelyhood(props->getDropLikelyHood());

	return e;
}

void Enemy::setNumOfDrops(int n)
{
	numOfDrops = n;
}

void Enemy::setLikelyhood(float l)
{
	likelyhood = l;
}