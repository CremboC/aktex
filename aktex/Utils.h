#pragma once
class Utils
{
public:
	Utils();
	~Utils();

	// generate a random number from x to y
	static int random(int from, int to);

	// generate a random float from x to y
	static float random(float from, float to);
};
