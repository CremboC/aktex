#include "stdafx.h"
#include "Screens.h"

#include "Screen.h"
#include "EnemyProperties.h"
#include "Item.h"

#include "State.h"

using std::pair;

using enums::GameState;

Screens::Screens(State *state)
{
	this->state = state;
}

Screens::~Screens()
{}

// returns the start screen
Screen *Screens::main()
{
	Screen *main = new Screen(
		"menu",
		"Welcome to Aktex. The adventure action text game. \n"
		"To start the game type in start and press enter! \n"
		"Also try 'options' for options or 'exit' to exit the game \n",
		{ "start", "exit", "options" },
		nullptr
		);

	State *state = this->state;

	main->defineMoveBehaviour("start", [state]
	{
	});

	main->defineMoveBehaviour("exit", [state]
	{
		state->setState(GameState::ENDED);
	});

	return main;
}

// the first game screen
Screen *Screens::start()
{
	vector<Item *> items = { new Item() };

	EnemyProperties *startEProps = new EnemyProperties;
	startEProps
		->hpRange(pair < int, int > {80, 100})
		->possibleDrops(1)
		->dropLikelyhood(0.5f)
		->items(items);

	return NULL;
}