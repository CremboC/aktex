#include "stdafx.h"
#include "DefaultCommands.h"

#include "io.h"

using std::string;

DefaultCommands::DefaultCommands()
{}

DefaultCommands::~DefaultCommands()
{}

void DefaultCommands::go(string params...)
{
	va_list args;
	va_start(args, params);

	string i = va_arg(args, string);

	io::puts(i);

	va_end(args);
}

void DefaultCommands::inventory(string params...)
{
	va_list args;
	va_start(args, params);

	va_end(args);
}