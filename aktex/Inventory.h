#pragma once

#include "Item.h"

using types::Vec;

class Inventory
{
private:
	Vec<Item *> items;

	Item *weapon;
	Item *armor;

public:
	Inventory();
	~Inventory();

	Vec<Item *> getItems();
	Item *getItem(int id);

	void putItem(Item *item);

	void equip(Item *item);
};
