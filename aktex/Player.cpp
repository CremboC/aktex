#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	this->inventory = new Inventory();
	hp = 100;
	damage = 3;
	defence = 5;
}

Player::~Player()
{}

Inventory *Player::getInventory()
{
	return inventory;
}