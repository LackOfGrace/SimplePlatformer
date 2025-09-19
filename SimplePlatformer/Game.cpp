#include "Game.h"

Game::Game()
{
	running = false;
	window = NULL;
	renderer = NULL;

	player = NULL;
	world = NULL;
}

void Game::Start()
{
	// Create a window
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
	}

	if (!SDL_CreateWindowAndRenderer("SimplePlatformer", 640, 480, 0, &window, &renderer))
	{
		SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
	}

	// Create the world
	world = new	World(40, 30,
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                                      X"
		"X                  XXXXXXX             X"
		"X                                      X"
		"X       XXXXXXX                XXX     X"
		"X                                      X"
		"XXX                        X           X"
		"XXX                       XX           X"
		"XXXXXX                   XXX           X"
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
	);


	// Create player
	player = new Player(world);

	running = true;
}

void Game::Stop()
{
	// Shutdown
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::Update()
{
	Uint64 startTicks = SDL_GetTicks();

	PollEvents(); // Go through application events, such as window closed by user
	UpdateEntities(); // Update all active entities
	Draw(); // Draw to the screen


	// Framelimit to around 60fps
	Uint64 endTicks = SDL_GetTicks();
	float elapsed = (endTicks - startTicks);

	if (elapsed < 16)
	{
		SDL_Delay(16 - elapsed);
	}
}

bool Game::ShouldClose()
{
	return !running;
}

void Game::DrawRect(int x, int y, int width, int height, int r, int g, int b)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
	SDL_FRect rect;
	rect.x = x;
	rect.y = 480 - height - y; // Screen space is flipped vertically, so im unflipping it here
	rect.w = width;
	rect.h = height;
	SDL_RenderFillRect(renderer, &rect);
}

void Game::PollEvents()
{
	// Here we go through events that happened to our game.
	// For now we are only looking for the event that tells us the user closed the window

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
		{
			running = false;
		}
	}
}

void Game::UpdateEntities()
{
	player->Update();
}

void Game::Draw()
{
	// Clear the screen
	SDL_SetRenderDrawColor(renderer, 10, 20, 30, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	// Draw game parts
	world->Draw(this);
	player->Draw(this);

	// Push to screen
	SDL_RenderPresent(renderer);
}