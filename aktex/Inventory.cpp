#include "stdafx.h"
#include "Inventory.h"

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
