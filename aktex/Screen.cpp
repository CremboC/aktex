#include "stdafx.h"

#include <functional>
#include <iostream>

#include "Screen.h"

#include "EnemyProperties.h"

Screen::Screen(string name, string text, vector<string> allowedMoves, EnemyProperties *properties)
{
	this->name = name;
	this->text = text;
	this->allowedMoves = allowedMoves;
	this->enemyProperties = properties;
}

Screen::~Screen()
{}

string Screen::getName()
{
	return this->name;
}

string Screen::getText()
{
	return this->text;
}

vector<string> Screen::getAllowedMoves()
{
	return this->allowedMoves;
}

EnemyProperties *Screen::getEnemyProperties()
{
	return this->enemyProperties;
}

void Screen::defineMoveBehaviour(string move, std::function<void()> func)
{
	moveBehaviours[move] = func;
}

void Screen::doMove(string move)
{
	auto fMove = moveBehaviours[move];

	fMove();

	if (true)
	{
	}
}