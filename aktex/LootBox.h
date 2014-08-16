#pragma once
#include "Spawnable.h"
#include "Item.h"

class LootBox :
	public Spawnable
{
private:
	bool open = false;

	Item *generateItem();

public:
	LootBox();
	~LootBox();

	void action();
	string realType();
};
