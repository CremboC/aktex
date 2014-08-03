#pragma once

using std::string;

namespace enums
{
	enum class GameState
	{
		RUNNING,
		PLAYING,
		PAUSED,
		ENDED
	};

	enum class Directions
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
}