#pragma once

#include "Item.h"

using types::Vec;

class Inventory
{
private:
	Vec<Item *> items;

public:
	Inventory();
	~Inventory();

	Vec<Item *> getItems();
	Item *getItem();

	void putItem(Item *item);
};
