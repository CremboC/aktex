#include "stdafx.h"

#include "Utils.h"

#include <sstream>
#include <random>
#include <iostream>

using std::stringstream;

using types::Vec;

Utils::Utils()
{}

Utils::~Utils()
{}

// generate a random number from x to y
int Utils::random(int from, int to)
{
	std::default_random_engine generator(rand());
	std::uniform_int_distribution<int> distribution(from, to);

	return distribution(generator);
}

// generate a random flaot from x to y
float Utils::random(float from, float to)
{
	std::default_random_engine generator(rand());
	std::uniform_real_distribution<float> distribution(from, to);

	return distribution(generator);
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