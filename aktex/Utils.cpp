#include "stdafx.h"

#include "Utils.h"

#include <sstream>
#include <random>
#include <iostream>
#include <ctime>

using std::stringstream;

using types::Vec;

Utils::Utils()
{}

Utils::~Utils()
{}

// generate a random number from x to y
int Utils::random(int from, int to)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(from, to);

	return distribution(gen);
}

// generate a random float from x to y
float Utils::random(float from, float to)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> distribution(from, to);

	return distribution(gen);
}

Vec<string> Utils::split(const string &s, char delim)
{
	Vec<string> elems;

	stringstream ss(s);
	string item;

	while (std::getline(ss, item, delim))
	{
		if (item.size() != 0)
			elems.push_back(item);
	}

	return elems;
}