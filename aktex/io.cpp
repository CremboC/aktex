#include "stdafx.h"
#include "io.h"

#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;

using std::endl;

using enums::ItemSpeed;
using enums::ItemType;
using enums::ItemSubType;

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

// prints a newline
void io::puts()
{
	cout << endl;
}

void io::puts(int x)
{
	for (int i = 0; i < x; i++)
	{
		cout << endl;
	}
}

// prints a string using cout without newline at the end
void io::print(string out)
{
	cout << out;
}

Vec<Item *> io::readItemsFile()
{
	std::ifstream infile("../itm.dat");

	Vec<Item *> items;

	string name;
	int dmg, type, speed, subtype;

	string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);

		if (!(iss >> name >> dmg >> type >> subtype >> speed))
			continue;

		ItemType itemType = static_cast<ItemType>(type);
		ItemSubType itemSubType = static_cast<ItemSubType>(subtype);
		ItemSpeed itemSpeed = static_cast<ItemSpeed>(speed);

		items.push_back(new Item(name, dmg, itemType, itemSubType, itemSpeed));
	}

	return items;
}