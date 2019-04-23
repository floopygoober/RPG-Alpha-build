#ifndef GAME_H
#define GAME_H

#include "Libraries.h"
#include "SetupClass.h"
#include "Sprite.h"
#include "Character.h"
#include <math.h>
#include <string>
#include<fstream>

using namespace std;

class Game
{
public:
	Game(int _screenWidth, int _screenHeight);
	~Game();

	//public function used throughout the game run time
	void GameLoop();

private:
	//private variables to print only to our game screen
	float camX;
	float camY;

	int screenWidth;
	int screenHeight;
	int mousePositionX;
	int mousePositionY;
	bool quit;

	Character* player;
	Sprite* grass;
	SetupClass* setup;

};

#endif