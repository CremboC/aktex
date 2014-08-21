#include "stdafx.h"
#include "Enemy.h"

#include "Utils.h"
#include "io.h"
#include "State.h"

Enemy::Enemy()
{}

Enemy::Enemy(EnemyProperties *props)
{
	this->setNumOfDrops(props->getNumberOfPossibleDrops());
	this->setLikelyhood(props->getDropLikelyHood());
	this->setHp(Utils::random(
		props->getHpRange().first,
		props->getHpRange().second
		));
	this->setDamage(5);
	this->setDefence(2);

	int randomAdverb = Utils::random(0, consts::adverbs.size() - 1);
	string adverb = consts::adverbs[randomAdverb];

	int randomNoun = Utils::random(0, consts::nouns.size() - 1);
	string noun = consts::nouns[randomNoun];

	this->setName(adverb + " " + noun);
}

Enemy::~Enemy()
{}

void Enemy::action()
{
	GameState s = State::inst().getCurrentState();
	Message *m = State::inst().getMessage();

	if (s == GameState::PLAYING)
	{
		m->append("Encountered " + name + "!");
		//io::puts("Encountered " + name + "!");
		//io::puts(name + " has " + std::to_string(hp)
		//	+ "hp and deals "
		//	+ std::to_string(damage)
		//	+ " damage per hit");

		m->append(name + " has " + std::to_string(hp)
			+ "hp and deals "
			+ std::to_string(damage)
			+ " damage per hit");
	}

	State::inst().setState(GameState::FIGHTING);
}

string Enemy::realType()
{
	return "Enemy";
}

void Enemy::setNumOfDrops(int n)
{
	numOfDrops = n;
}

void Enemy::setLikelyhood(float l)
{
	likelyhood = l;
}