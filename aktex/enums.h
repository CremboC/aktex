#pragma once

namespace enums
{
	enum class GameState
	{
		RUNNING,
		PLAYING,
		PAUSED,
		ENDED
	};

	enum class Direction
	{
		N,
		NE,
		E,
		SE,
		S,
		SW,
		W,
		NW
	};

	enum class ItemSpeed
	{
		NA = 0,
		FAST = 1,
		NORMAL = 2,
		SLOW = 4
	};

	enum class ItemType
	{
		ARMOR = 1,
		WEAPON_DAGGER = 2,
		WEAPON_SWORD = 4,
		WEAPON_AXE = 8,
		WEAPON_MACE = 16
	};
}