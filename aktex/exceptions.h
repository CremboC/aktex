#pragma once

using std::string;

namespace exceptions
{
	class Exception
	{
	protected:
		string message;

	public:
		Exception(string msg) { this->message = msg; }
		string getMessage() { return message; };
	};

	class IllegalStateException : public Exception
	{
	public:
		IllegalStateException(string msg) : Exception(msg)
		{}
	};

	class IllegalMoveException : public Exception
	{
	public:
		IllegalMoveException(string msg) : Exception(msg)
		{}
	};

	class NonOverriddenMoveException : public Exception
	{
	public:
		NonOverriddenMoveException(string msg) : Exception(msg)
		{}
	};
}