#include "stdafx.h"
#include "Item.h"

Item::Item(string name, int stat, ItemType type, ItemSubType subtype, ItemSpeed speed)
{
	this->name = name;
	this->stat = stat;
	this->type = type;
	this->subtype = subtype;
	this->speed = speed;
}

Item::Item(Item *item)
{
	name = item->getName();
	stat = item->getStat();
	type = item->getType();
	subtype = item->getSubtype();
	speed = item->getSpeed();
}

Item::~Item()
{}

string Item::toString()
{
	return "Item: " + name +
		" stat: " + std::to_string(stat) +
		" type: " + " " +
		" speed: " + " ";
}