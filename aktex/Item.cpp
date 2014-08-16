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
	name = item->getName();
	stat = item->getStat();
	type = item->getType();
	speed = item->getSpeed();
}

Item::~Item()
{}

Item *Item::clone()
{
	return new Item(this);
}

string Item::toString()
{
	return "Item: " + name +
		" stat: " + std::to_string(stat) +
		" type: " + " " +
		" speed: " + " ";


}

