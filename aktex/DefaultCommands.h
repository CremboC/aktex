#pragma once

#include <cstdarg>

class DefaultCommands
{
private:

public:
	DefaultCommands();
	~DefaultCommands();

	static void go(string params...);

	static void inventory(string params...);
};
