#pragma once

using std::string;

using types::Vec;

class DefaultCommands
{
private:

	Vec<string> defaultCommands;

public:
	DefaultCommands();
	~DefaultCommands();

	void go(string direction);

	void inventory(string secondary, string fin);
	void inventory(string secondary);
	void inventory();

	void attack();

	bool exists(string move);

	void call(Vec<string> params);
};
