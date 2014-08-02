#include "stdafx.h"
#include "io.h"

#include <iostream>

using std::cout;
using std::cin;

using std::endl;

io::io()
{}

io::~io()
{}

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