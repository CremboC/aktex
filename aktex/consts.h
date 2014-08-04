#pragma once

using std::string;

using types::HashMap;

using enums::Direction;

namespace consts
{
	// maps string to direction enum
	const HashMap<string, Direction> directionsMap{
			{ "north", Direction::N },
			{ "northeast", Direction::NE },
			{ "east", Direction::E },
			{ "southeast", Direction::SE },
			{ "south", Direction::S },
			{ "southwest", Direction::SW },
			{ "west", Direction::W },
			{ "northwest", Direction::NW }
	};
}