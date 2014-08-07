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
	float getDamage();

private:
	int hp = 0;
	string name;
	float damage = 0;
};
