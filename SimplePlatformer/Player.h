#pragma once
#include "World.h"
#include "Button.h"

class Game;

class Player
{
public:
	Player(World* world);

	void Draw(Game* game);
	void Update();

private:
	World* world;

	float x;
	float y;

	float vy;

	bool isGrounded;

	Button left = Button(SDL_Scancode::SDL_SCANCODE_LEFT);
	Button right = Button(SDL_Scancode::SDL_SCANCODE_RIGHT);
	Button jump = Button(SDL_Scancode::SDL_SCANCODE_SPACE);
};

