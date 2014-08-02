#pragma once

#include <vector>
#include <unordered_map>

#include "Screen.h"
#include "Player.h"

using std::unordered_map;
using std::string;

class Game
{
private:
	typedef std::unordered_map<string, Screen *> ss_hashmap;

	ss_hashmap availableScreens;
	Player player;

public:
	Game();
	~Game();

	void start(Screen *initialScreen);
};
