#include "stdafx.h"
#include "Entity.h"

Entity::Entity()
{}

Entity::~Entity()
{}

void Entity::setHp(int hp)
{
	this->hp = hp;
}

void Entity::setName(string name)
{
	this->name = name;
}

int Entity::getHp()
{
	return hp;
}

string Entity::getName()
{
	return name;
}

float Entity::getDamage()
{
	return damage;
}