#pragma once

#include "Entity.h"
#include "Inventory.h"

class Player :
	public Entity
{
public:
	Player();
	~Player();
private:
	Inventory *inventory;
};
