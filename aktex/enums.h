#pragma once

namespace enums
{
	enum class GameState
	{
		RUNNING,
		PLAYING,
		PAUSED,
		FIGHTING,
		ENDED
	};

	enum class Direction
	{
		C, // centre
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
		WEAPON = 2,
	};

	enum class ItemSubType
	{
		WEAPON_DAGGER = 1,
		WEAPON_SWORD = 2,
		WEAPON_AXE = 4,
		WEAPON_MACE = 8
	};
}