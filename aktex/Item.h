#pragma once

using enums::ItemType;
using enums::ItemSpeed;

using std::string;

class Item
{
private:
	string name;
	// can be damage or defence
	int stat;

	ItemType type;
	ItemSpeed speed;

public:
	Item(Item *item);
	Item(string name, int damage, ItemType type, ItemSpeed speed);
	~Item();

	int getStat() const { return stat; }

	string getName() const { return name; }

	ItemType getType() const { return type; }

	ItemSpeed getSpeed() const { return speed; }

	Item *clone();

	string toString();
};
