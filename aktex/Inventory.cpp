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