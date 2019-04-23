#ifndef SETUPCLASS_H
#define SETUPCLASS_H

#include "Libraries.h"

using namespace std;

class SetupClass
{
public:
	//constructors and deconstructors
	SetupClass(bool* quit, int screenWidth, int screenHeight);
	~SetupClass();

	//public functions to start and end the game with no memory leaks
	void Begin();
	void End();

	//accessors
	inline SDL_Renderer* GetRenderer() { return renderer; }
	inline SDL_Event* GetMainEvent() { return mainEvent; }

private:
	//drawing/creating our window
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
};

#endif