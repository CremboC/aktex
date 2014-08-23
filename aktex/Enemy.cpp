#include "stdafx.h"
#include "Enemy.h"

#include "Utils.h"
#include "State.h"

Enemy::Enemy()
{}

Enemy::Enemy(EnemyProperties &props)
{
	numOfDrops = props.getNumberOfPossibleDrops();
	likelyhood = props.getDropLikelyHood();
	hp = Utils::random(props.getHpRange().first, props.getHpRange().second);
	damage = 5;
	defence = 2;

	int randomAdverb = Utils::random(0, consts::adverbs.size() - 1);
	string adverb = consts::adverbs[randomAdverb];

	int randomNoun = Utils::random(0, consts::nouns.size() - 1);
	string noun = consts::nouns[randomNoun];

	name = adverb + " " + noun;
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

		m->append(name + " has " + std::to_string(hp)
			+ "hp and deals "
			+ std::to_string(damage)
			+ " damage per hit");

		State::inst().setCurrentEnemy(this);
	}

	State::inst().setState(GameState::FIGHTING);
}

string Enemy::realType()
{
	return "Enemy";
}