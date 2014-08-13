#pragma once

using enums::ItemType;
using enums::ItemSpeed;

using std::string;

class Item
{
private:
	string name;
	int damage;

	ItemType type;
	ItemSpeed speed;


public:
	Item();
	virtual ~Item();

	string getName();
	int getDamage();
};
