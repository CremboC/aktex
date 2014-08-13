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
		FAST,
		NORMAL,
		SLOW
	};

	enum class ItemType
	{
		ARMOR,
		WEAPON_DAGGER,
		WEAPON_SWORD,
		WEAPON_AXE,
		WEAPON_MACE
	};
}