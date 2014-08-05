#include "stdafx.h"
#include "Utils.h"

#include <random>

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