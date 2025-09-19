#include "World.h"
#include "Game.h"


World::World(int w, int h, const char* data)
{
	width = w;
	height = h;
	roomData = data;
}

bool World::Collision(int x, int y)
{
	// Convert world coordinates to level cell and check state

	int cellX = x / 16;
	int cellY = y / 16;

	if (cellX < 0 || cellX > width) return true;
	if (cellY < 0 || cellY > height) return true;

	return roomData[(height - cellY - 1) * width + cellX] != ' ';
}

void World::Draw(Game* game)
{
	// Iterate through all cells and draw correct tile
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			if (roomData[(height - y - 1) * width + x] == 'X')
			{
				game->DrawRect(x * 16, y * 16, 16, 16, 100, 100, 100);
			}
		}
	}
}