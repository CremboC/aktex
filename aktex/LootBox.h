#pragma once
#include "Spawnable.h"
class LootBox :
	public Spawnable
{
public:
	LootBox();
	~LootBox();

	void action();
	string realType();
};
