#include "stdafx.h"
#include "DefaultCommands.h"

#include "State.h"
#include "Inventory.h"
#include "Item.h"
#include "Player.h"

using consts::directionsMap;
using consts::directionExists;

using exceptions::IllegalStateException;

DefaultCommands::DefaultCommands()
{
	defaultCommands = { "go", "inventory", "attack", "stats", "exit" };
}

DefaultCommands::~DefaultCommands()
{}

void DefaultCommands::go(string direction)
{
	Player *player = State::inst().getPlayer();
	Screen *scr = State::inst().getCurrentScreen();
	GameState state = State::inst().getCurrentState();
	Message *m = State::inst().getMessage();

	if (state == GameState::FIGHTING)
	{
		m->append("Cannot run away from a fight in this game!");
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
	Message *m = State::inst().getMessage();
	Inventory *in = State::inst().getPlayer()->getInventory();

	string inventory = "  #  |  Name  |  Stat  |  \n";
	inventory += "--------------------------\n";

	int i = 1;
	for (Item *item : in->getItems())
	{
		inventory += " "
			+ std::to_string((int) i++) + " | "
			+ item->getName() + " | "
			+ std::to_string(item->getStat()) + " | \n";
	}
	inventory += "--------------------------\n";

	m->append(inventory);
}

void DefaultCommands::inventory(string secondary)
{}

void DefaultCommands::inventory(string secondary, string fin)
{
	Message *m = State::inst().getMessage();
	Player *p = State::inst().getPlayer();
	Inventory *in = p->getInventory();

	if (secondary == "equip")
	{
		Item *toEquip = in->getItem(std::stoi(fin));

		if (toEquip == nullptr)
		{
			throw new IllegalStateException("Item doesn't exist");
		}

		in->equip(toEquip);

		switch (toEquip->getType())
		{
		case ItemType::ARMOR:
			p->setDefence(p->getDefence() + toEquip->getStat());
			break;

		case ItemType::WEAPON:
			p->setDamage(p->getDamage() + toEquip->getStat());
			break;

		default:
			break;
		}

		return;
	}

	if (secondary == "unequip")
	{

		return;
	}
}

void DefaultCommands::stats()
{
	Message *m = State::inst().getMessage();
	Player *p = State::inst().getPlayer();

	string s = "Player stats: "
		"\nHealth  : " + std::to_string(p->getHp()) +
		"\nDamage  : " + std::to_string(p->getDamage()) +
		"\nDefence : " + std::to_string(p->getDefence());

	m->append(s);

	return;
}

void DefaultCommands::attack()
{
	Player *p = State::inst().getPlayer();
	Enemy *e = State::inst().getCurrentEnemy();

	int dmg = p->getDamage();
	int enemyHp = e->getHp();
}

bool DefaultCommands::exists(string move)
{
	for (string cmd : defaultCommands)
	{
		if (cmd == move)
			return true;
	}

	return false;
}

// returns whether a command is special - i.e. skip act?
bool DefaultCommands::call(Vec<string> params)
{
	string command = params[0];

	// go should only have one additional param - direction
	if (command == "go" && params.size() == 2)
	{
		go(params[1]);

		return false;
	}

	if (command == "stats")
	{
		stats();

		return true;
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

		return true;
	}

	if (command == "attack")
	{
		attack();

		return false;
	}

	if (command == "exit")
	{
		State::inst().setState(GameState::ENDED);

		return false;
	}

	return false;
}