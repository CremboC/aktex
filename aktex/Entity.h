#pragma once

using std::string;

class Entity
{
public:
	Entity();
	virtual ~Entity();

	void setHp(int hp);
	void setName(string name);

	int getHp();
	string getName();
	int getDamage();

protected:
	int hp = 0;
	string name;
	int damage = 0;
	int defence = 0;
};
