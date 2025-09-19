#include "Game.h"


int main()
{
	// I try to get away from main as soon as possbile.
	// Do the least amount of work to start your game
	// Everything fun is located in Game

	Game game;

	game.Start();

	while (!game.ShouldClose())
	{
		game.Update();
	}

	game.Stop();

	return 0;
}