#include "stdafx.h"
#include "Tutorial.h"


Tutorial::Tutorial()
{}

Tutorial::~Tutorial()
{}

bool Tutorial::fighting()
{
	static bool finished = false;

	return finished;
}

bool Tutorial::equiping()
{
	static bool finished = false;

	return finished;
}

// started when player enters first room
bool Tutorial::general()
{
	static bool finished = false;

	return finished;
}
