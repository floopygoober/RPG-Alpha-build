#include "Game.h"

//setting up our background image and drawing our initial values to our screen on start
Game::Game(int _screenWidth, int _screenHeight)
{
	camX = 0;
	camY = 0;

	screenWidth = _screenWidth;
	screenHeight = _screenHeight;
	quit = false;
	setup = new SetupClass(&quit, screenWidth, screenHeight);

	grass = new Sprite(setup->GetRenderer(), "Pictures/grass.bmp", 0, 0, screenWidth, screenHeight, &camX, &camY);

	mousePositionX = 0;
	mousePositionY = 0;

	player = new Character(setup, &mousePositionX, &mousePositionY, &camX, &camY);
}

//deconstructing on close to clear up more memory and not be a crashy boi
Game::~Game()
{
	delete setup;
	delete grass;
	delete player;
}

//a constant to maintain game fps
void Game::GameLoop()
{
	while (!quit &&	setup->GetMainEvent()->type != SDL_QUIT)
	{
		setup->Begin();
		SDL_GetMouseState(&mousePositionX, &mousePositionY);

		grass->Draw();
		player->Draw();

		player->Update();

		setup->End();
	}
}