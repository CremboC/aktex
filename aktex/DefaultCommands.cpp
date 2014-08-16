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
	Player *player = State::getInstance().getPlayer();
	Screen *scr = State::getInstance().getCurrentScreen();

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
	Inventory *in = State::getInstance().getPlayer()->getInventory();

	Vec<Item *> items = in->getItems();

	for (auto item : items)
	{
		io::puts(item->getName());
	}
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
	Player *p = State::getInstance().getPlayer();

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
		State::getInstance().setState(GameState::ENDED);
	}
}
