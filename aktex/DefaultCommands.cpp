#include "stdafx.h"
#include "DefaultCommands.h"

#include "State.h"
#include "Inventory.h"
#include "Item.h"
#include "Player.h"

#include "io.h"

DefaultCommands::DefaultCommands()
{
	defaultCommands = { "go", "inventory" };
}

DefaultCommands::~DefaultCommands()
{}

void DefaultCommands::go(string direction)
{}

void DefaultCommands::inventory()
{
	Inventory *in = State::getInstance().getPlayer()->getInventory();

	Vec<Item *> items = in->getItems();
}

void DefaultCommands::inventory(string secondary)
{
	io::puts("secondary: " + secondary);
}

void DefaultCommands::inventory(string secondary, string fin)
{
	io::puts("secondary: " + secondary + " fin: " + fin);
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

	// go should only have one additiona param - direction
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
}