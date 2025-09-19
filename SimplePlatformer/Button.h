#pragma once
#include "SDL3/SDL.h"

class Button
{
public:
	Button(SDL_Scancode k);

	void Update();
	bool IsDown();
	bool WasPressed();

private:
	SDL_Scancode key;
	bool isDown;
	bool wasPressed;
};

