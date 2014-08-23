#pragma once

using enums::ItemType;
using enums::ItemSpeed;
using enums::ItemSubType;

using std::string;

class Item
{
private:
	string name;
	// can be damage or defence
	int stat;

	ItemType type;
	ItemSubType subtype;
	ItemSpeed speed;

public:
	Item(Item *item);
	Item(string name, int damage, ItemType type, ItemSubType subtype, ItemSpeed speed);
	~Item();

	int getStat() const { return stat; }
	string getName() const { return name; }
	ItemType getType() const { return type; }
	ItemSpeed getSpeed() const { return speed; }
	ItemSubType getSubtype() const { return subtype; }

	string toString();
};
