#include "stdafx.h"
#include "Item.h"

Item::Item(string name, int damage, ItemType type, ItemSpeed speed)
{
	this->name = name;
	this->damage = damage;
	this->type = type;
	this->speed = speed;
}

Item::Item(Item *item)
{
	Item(item->getName(), item->getDamage(), item->getType(), item->getSpeed());
}

Item::~Item()
{}

Item *Item::clone()
{
	return new Item(this);
}

