#include "stdafx.h"
#include "Enemy.h"

#include "Utils.h"
#include "io.h"
#include "State.h"

Enemy::Enemy()
{}

Enemy::Enemy(Enemy *e)
{}

Enemy::~Enemy()
{}

void Enemy::action()
{
	GameState s = State::getInstance().getCurrentState();
	
	if (s == GameState::PLAYING)
	{
		io::puts("Encountered " + name + "!");
		io::puts(name + " has " + std::to_string(hp) + " and deals " + std::to_string(damage));
	}

	State::getInstance().setState(GameState::FIGHTING);
}

string Enemy::realType()
{
	return "Enemy";
}

Enemy *Enemy::build(EnemyProperties *props)
{
	Enemy *e = new Enemy();

	e->setNumOfDrops(props->getNumberOfPossibleDrops());
	e->setLikelyhood(props->getDropLikelyHood());
	e->setHp(Utils::random(
		props->getHpRange().first,
		props->getHpRange().second
		));

	int randomAdverb = Utils::random(0, consts::adverbs.size());
	string adverb = consts::adverbs[randomAdverb];

	int randomNoun = Utils::random(0, consts::nouns.size());
	string noun = consts::nouns[randomNoun];

	e->setName(adverb + " " + noun);

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