#pragma once

using std::string;

using types::Vec;

class Utils
{
public:
	Utils();
	~Utils();

	// generate a random number from x to y
	static int random(int from, int to);

	// generate a random float from x to y
	static float random(float from, float to);

	static string concat(Vec<string> ss);

	static Vec<string> split(const string &s, char delim);
};
