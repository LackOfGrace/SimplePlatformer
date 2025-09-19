#pragma once
#include "SDL3/SDL.h"

#include "World.h"
#include "Player.h"

class Game
{
public:
	Game();

	void Start();
	void Stop();

	void Update();
	bool ShouldClose();

	void DrawRect(int x, int y, int width, int height, int r, int g, int b);

private:
	void PollEvents();
	void UpdateEntities();
	void Draw();

	bool running;

	SDL_Window* window;
	SDL_Renderer* renderer;

	World* world;
	Player* player;
};

