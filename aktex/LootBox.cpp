#include "stdafx.h"
#include "LootBox.h"

#include "io.h"
#include "Utils.h"
#include "State.h"
#include "Item.h"
#include "Player.h"

LootBox::LootBox()
{}

LootBox::~LootBox()
{}

void LootBox::action()
{
	static Item *item = generateItem();

	if (open)
	{
		io::puts("This box is open, you probably want to go back now using 'go center'..");
		io::puts("you found here the following: ");

		io::puts(item->getName()
			+ " with stat of "
			+ std::to_string(item->getStat()));

		return;
	}

	io::puts(
		"You have found a loot box! "
		"It contains the following: "
		);

	io::puts(item->getName() 
		+ " with stat of " 
		+ std::to_string(item->getStat()) 
		+ ", it is now in your inventory");

	Player *p = State::getInstance().getPlayer();

	p->getInventory()->putItem(item);
	open = true;
}

string LootBox::realType()
{
	return "LootBox";
}

Item *LootBox::generateItem()
{
	Vec<Item *> items = State::getInstance().getItems();

	unsigned short randNumber = Utils::random(0, items.size() - 1);

	return new Item(items[randNumber]);
}
