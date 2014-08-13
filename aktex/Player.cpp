#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	this->inventory = new Inventory();
}

Player::~Player()
{}

Inventory *Player::getInventory()
{
	return inventory;
}