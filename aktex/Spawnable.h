#pragma once

using std::string;

using types::Func;

class Spawnable
{
protected:
	const string mText;

public:
	Spawnable();
	virtual ~Spawnable();

	string text();

	// defines what happens once this spawnable has been "reached"
	virtual void action() = 0;
};
