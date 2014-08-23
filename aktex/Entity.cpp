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

int Entity::getDamage()
{
	return damage;
}

void Entity::setDamage(int damage)
{
	this->damage = damage;
}

void Entity::setDefence(int defence)
{
	this->defence = defence;
}

int Entity::getDefence()
{
	return defence;
}