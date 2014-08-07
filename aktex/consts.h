#pragma once

using std::string;

using types::HashMap;
using types::Vec;

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

	const Vec<string> adverbs{
		"Badass", "Unknowing", "Ridiculous",
		"Strong", "Witty", "Insightful",
		"Quick", "Crazy", "Peasant",
		"Slow", "Reckless", "Sir",
		"Boring", "Mad", "Rare",
		"Naive", "Insane"
	};

	const Vec<string> nouns{
		"Jean-Luc", "Jean-Michel", "Damm",
		"Villager", "Jack", "John", "Roach",
		"Keith", "Fief", "Swordsman", "Crossbowman",
		"Longswordsman", "King"
	};

	const Vec<string> commands{
		"go", "inventory", "restart"
	};
}