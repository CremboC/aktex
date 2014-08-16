#include "stdafx.h"
#include "Item.h"

Item::Item(string name, int stat, ItemType type, ItemSpeed speed)
{
	this->name = name;
	this->stat = stat;
	this->type = type;
	this->speed = speed;
}

Item::Item(Item *item)
{
	Item(item->getName(), item->getStat(), item->getType(), item->getSpeed());
}

Item::~Item()
{}

Item *Item::clone()
{
	return new Item(this);
}

