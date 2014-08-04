#pragma once

#include "Entity.h"
#include "Spawnable.h"

class Enemy
	: public Entity, public Spawnable
{
public:
	Enemy();
	~Enemy();
};
