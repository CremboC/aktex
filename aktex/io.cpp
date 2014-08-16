#include "stdafx.h"
#include "io.h"

#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;

using std::endl;

io::io()
{}

io::~io()
{}

string io::multiInput()
{
	string input;
	std::getline(cin, input);

	return input;
}

// returns a string representation of the user input
string io::strInput()
{
	string input;
	cin >> input;

	return input;
}

// returns an int representation of the user input
int io::intInput()
{
	int inp;
	cin >> inp;

	return inp;
}

// prints a string using cout
void io::puts(string out)
{
	cout << out << endl;
}

// prints a string using cout without newline at the end
void io::print(string out)
{
	cout << out;
}

// prints items in a nice format
void io::printItems(Vec<Item *> items)
{
	for (auto a : items)
	{
		//cout << a->
	}
}

Vec<Item *> io::readItemsFile()
{
	std::ifstream infile("../itm.dat");

	Vec<Item *> items;

	string name;
	int dmg, type, speed;

	string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		if (!(iss >> name >> dmg >> type >> speed)) 
			continue;

		ItemType itemType = static_cast<ItemType>(type);
		ItemSpeed itemSpeed = static_cast<ItemSpeed>(speed);

		items.push_back(new Item(name, dmg, itemType, itemSpeed));

	}

	return items;
}
