#include "Player.h"
#include "Game.h"

Player::Player(World* w)
{
	world = w;
	x = 200;
	y = 200;
	isGrounded = false;
}

void Player::Draw(Game* game)
{
	game->DrawRect(x, y, 16, 32, 255, 255, 255);
}

void Player::Update()
{
	// Update input
	left.Update();
	right.Update();
	jump.Update();

	float newX = x;
	float newY = y;

	// Gravity
	vy -= 0.3f;
	newY += vy;

	// Horizontal movement
	if (left.IsDown()) newX -= 3;
	if (right.IsDown()) newX += 3;

	// Collision check down
	if (!world->Collision(x, newY) && !world->Collision(x + 16, newY))
	{
		y = newY;
		isGrounded = false;
	}
	else
	{
		isGrounded = true;
		vy = 0;
	}

	// Jumping
	if (isGrounded && jump.WasPressed())
	{
		vy = 8;
	}

	// Collision check horizontal
	if (!world->Collision(newX, y) && !world->Collision(newX + 16, y))
	{
		x = newX;
	}
}