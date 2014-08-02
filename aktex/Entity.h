#pragma once

using std::string;

class Entity
{
public:
	Entity();
	virtual ~Entity();
private:
	int hp;
	string name;
};
