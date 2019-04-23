#ifndef CHARACTER_H
#define CHARACTER_H

#include "Libraries.h"
#include "Sprite.h"
#include "SetupClass.h"
#include <math.h>

class Character
{
public:
	Character(SetupClass* setup, int *mousePosX, int *mousePosY, float *cameraX, float *cameraY);
	~Character();

	//functions we call in multiple classes for efficiency sake
	double getDistance(int x1, int y1, int x2, int y2);

	//animation and displaying
	void Update();
	void Draw();

private:
	//private functions only our character will be able to access
	void UpdateAnimation();
	void UpdateControls();

	float *camX;
	float *camY;

	int *mouseX;
	int *mouseY;

	SetupClass* setup;

	Sprite* player;
	int timeCheck;

	bool isFollowing;
	int followPointX;
	int followPointY;

	float distance;
	bool stopAnimation;
};

#endif