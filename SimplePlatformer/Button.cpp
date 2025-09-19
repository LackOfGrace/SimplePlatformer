#include "Button.h"

Button::Button(SDL_Scancode k)
{
	key = k;
	isDown = false;
	wasPressed = false;
}

void Button::Update()
{
	const bool* keys = SDL_GetKeyboardState(NULL);


	bool state = keys[key];

	wasPressed = !isDown && state;
	isDown = state;
}

bool Button::IsDown()
{
	return isDown;
}

bool Button::WasPressed()
{
	return wasPressed;
}