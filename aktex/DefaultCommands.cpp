#include "stdafx.h"
#include "DefaultCommands.h"

#include "State.h"
#include "Inventory.h"
#include "Item.h"
#include "Player.h"

#include "io.h"

using consts::directionsMap;
using consts::directionExists;

DefaultCommands::DefaultCommands()
{
	defaultCommands = { "go", "inventory", "exit" };
}

DefaultCommands::~DefaultCommands()
{}

void DefaultCommands::go(string direction)
{
	Player *player = State::inst().getPlayer();
	Screen *scr = State::inst().getCurrentScreen();
	GameState state = State::inst().getCurrentState();

	if (state == GameState::FIGHTING)
	{
		io::puts("Cannot run away from a fight in this game!");
		return;
	}

	if (directionExists(direction))
	{
		Direction dir = directionsMap.at(direction);

		if (!scr->isLocEmpty(dir) || dir == Direction::C)
		{
			player->setPosition(dir);
		}
	}
}

void DefaultCommands::inventory()
{
	Inventory *in = State::inst().getPlayer()->getInventory();

	io::puts("  #  |  Name  |  Stat  |  ");
	io::puts("--------------------------");

	int i = 1;
	for (Item *item : in->getItems())
	{
		io::puts(" " 
			+ std::to_string((int) i++) + " | " 
			+ item->getName() + " | " 
			+ std::to_string(item->getStat()) + " | ");

	}
	io::puts("--------------------------");
}

void DefaultCommands::inventory(string secondary)
{
	// io::puts("secondary: " + secondary);
}

void DefaultCommands::inventory(string secondary, string fin)
{
	// io::puts("secondary: " + secondary + " fin: " + fin);
}

void DefaultCommands::attack()
{
	Player *p = State::inst().getPlayer();

	int dmg = p->getDamage();
}

bool DefaultCommands::exists(string move)
{
	for (auto cmd : defaultCommands)
	{
		if (cmd == move)
			return true;
	}

	return false;
}

void DefaultCommands::call(Vec<string> params)
{
	string command = params[0];

	// go should only have one additional param - direction
	if (command == "go" && params.size() == 2)
	{
		go(params[1]);
	}

	if (command == "inventory")
	{
		switch (params.size())
		{
		case 2:
			inventory(params[1]);
			break;

		case 3:
			inventory(params[1], params[2]);
			break;

		case 1:
		default:
			inventory();
			break;
		}
	}

	if (command == "exit")
	{
		State::inst().setState(GameState::ENDED);
	}
}
