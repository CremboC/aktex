#include "stdafx.h"
#include "Inventory.h"

using enums::ItemType;

Inventory::Inventory()
{}

Inventory::~Inventory()
{}

Vec<Item *> Inventory::getItems()
{
	return this->items;
}

void Inventory::putItem(Item *item)
{
	items.push_back(item);
}

void Inventory::equip(Item *item)
{
	switch (item->getType())
	{
	case ItemType::ARMOR:
		armor = item;
		break;

	case ItemType::WEAPON:
		weapon = item;
		break;

	default:
		// very bad
		break;
	}
}

Item *Inventory::getItem(int id)
{
	if (items.size() < id)
	{
		return nullptr;
	}

	return items.at(id - 1);
}