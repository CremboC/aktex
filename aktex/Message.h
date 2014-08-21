#pragma once

using types::Vec;

class Message
{
private:
	Vec<string> message;
public:
	Message();
	~Message();

	void flush();

	void append(string s);
	string get() const;
};
