#include "stdafx.h"
#include "Message.h"
#include "Utils.h"

Message::Message()
{}

Message::~Message()
{}

void Message::append(string s)
{
	message.push_back(s);
}

string Message::get() const
{
	return Utils::concat(message);
}

void Message::flush()
{
	message.clear();
	message.swap(Vec < string > {});
}