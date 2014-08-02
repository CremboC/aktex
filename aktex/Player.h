#pragma once

#include "Entity.h"
#include "Inventory.h"
#include "Screen.h"

class Player :
	public Entity
{
private:
	Inventory *inventory;

public:
	Player();
	~Player();

	Inventory *getInventory();
};
