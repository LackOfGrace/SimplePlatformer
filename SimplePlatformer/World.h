#pragma once

class Game;

class World
{
public:
	World(int width, int height, const char* roomData);

	void Draw(Game* game);

	bool Collision(int x, int y);

private:
	int width;
	int height;
	const char* roomData;
};

