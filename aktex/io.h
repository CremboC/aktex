#pragma once
class io
{
public:
	io();
	~io();

	// returns a string representation of the user input
	static string strInput();

	// returns an int representation of the user input
	static int intInput();

	// prints a string using cout with a newline at the end
	static void puts(string out);

	// prints a string using cout without newline at the end
	static void print(string out);
};
