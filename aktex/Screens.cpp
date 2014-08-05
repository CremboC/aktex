#include "stdafx.h"

#include "Screens.h"
#include "Game.h"

using std::pair;

using enums::GameState;

Screens::Screens()
{}

Screens::~Screens()
{}

// returns the start screen
Screen *Screens::main()
{
	Screen *scr = new Screen(
		"menu",
		"Welcome to Aktex. The adventure action text game. \n"
		"To start the game type in start and press enter! \n"
		"Also try 'options' for options or 'exit' to exit the game \n",
		{ "start", "exit", "options" },
		nullptr
		);

	scr->defineMoveBehaviour("start", [this]
	{
		State::getInstance().setState(GameState::PLAYING);
		State::getInstance().setScreen(start());
	});

	scr->defineMoveBehaviour("exit", [this]
	{
		State::getInstance().setState(GameState::ENDED);
	});

	return scr;
}

// the first game screen
Screen *Screens::start()
{
	vector<Item *> items = { new Item() };

	EnemyProperties *eProps = new EnemyProperties;
	eProps
		->hpRange(pair < int, int > {80, 100})
		->possibleDrops(1)
		->dropLikelyhood(0.5f)
		->items(items);

	Screen *scr = new Screen(
		"first",
		"Dis da' first game screen, wassup y'all. \n"
		"Youse in room, youse see door north of you. What you do?",
		{ "go {}", "exit" },
		eProps
		);

	return scr;
}

Screen *Screens::generateRoom()
{
	return nullptr;
}