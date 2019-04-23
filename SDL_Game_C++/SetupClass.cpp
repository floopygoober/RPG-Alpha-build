#include "SetupClass.h"

//Setting up our window variables and using them to draw to the screen
SetupClass::SetupClass(bool* quit, int screenWidth, int screenHeight)
{
	SDL_Init(SDL_INIT_VIDEO);
	window = NULL;
	window = SDL_CreateWindow("My Game", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		cout << "Cant load window" << endl;
		*quit = true;
	}

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	mainEvent = new SDL_Event();
}

//destroying on close to save yet more memory
SetupClass::~SetupClass()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}
//calling our functions from other classes on start for better organization
void SetupClass::Begin()
{
	SDL_PollEvent(GetMainEvent());
	SDL_RenderClear(GetRenderer());
}

//using our renderer on end to prevent memory leak
void SetupClass::End()
{
	SDL_RenderPresent(GetRenderer());
}