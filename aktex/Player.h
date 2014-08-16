#pragma once

#include "Entity.h"
#include "Inventory.h"

using enums::Direction;

class Player :
	public Entity
{
private:
	Inventory *inventory;

	Direction position;

public:
	Player();
	~Player();

	Inventory *getInventory();

	Direction getPosition() const { return position; }
	void setPosition(Direction val) { position = val; }
};
