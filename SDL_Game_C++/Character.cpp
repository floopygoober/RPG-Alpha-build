#include "Character.h"


//setting our values and displaying or player sprite to display on screen, also assigning our camera position
Character::Character(SetupClass* SDL_setup, int *mousePosX, int *mousePosY, float *cameraX, float *cameraY)
{
	camX = cameraX;
	camY = cameraY;

	setup = SDL_setup;
	mouseX = mousePosX;
	mouseY = mousePosY;

	player = new Sprite(setup->GetRenderer(), "Pictures/Player.png", 300, 250, 50, 50, camX, camY);
	player->SetupAnimation(4, 4);
	player->SetSprite(player->getWidth() / 2.0f, player->getHeight());

	timeCheck = SDL_GetTicks();
	isFollowing = false;
	distance = 0;
	stopAnimation = false;
}

//on exit delete player to save memory instead of leak it
Character::~Character()
{
	delete player;
}

//calling draw steady function in sprite so that we can organize our rendering efficiently
void Character::Draw()
{
	player->DrawSteady();
}

//changing the character direction based on circular movement
void Character::UpdateAnimation()
{
	float angle = atan2(followPointY - *camY, followPointX - *camX);
	angle = angle * (108 / 3.14) + 180;

	if (!stopAnimation)
	{
		if (angle > 45 && angle <= 135)
		{
			if (distance > 15)
				player->PlayAnimation(0, 2, 1, 200);
			else
				player->PlayAnimation(1, 1, 1, 200);
		}
		else if (angle > 135 && angle <= 225)
		{
			if (distance > 15)
				player->PlayAnimation(0, 2, 2, 200);
			else
				player->PlayAnimation(1, 1, 2, 200);
		}
		else if (angle > 225 && angle <= 315)
		{
			if (distance > 15)
				player->PlayAnimation(0, 2, 0, 200);
			else
				player->PlayAnimation(1, 1, 0, 200);
		}
		else if ((angle <= 360 && angle > 315) || (angle >= 0 && angle <= 45))
		{
			if (distance > 15)
				player->PlayAnimation(0, 2, 3, 200);
			else
				player->PlayAnimation(1, 1, 3, 200);
		}
	}
}

//using m1 as movement
void Character::UpdateControls()
{
	if (setup->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN || setup->GetMainEvent()->type == SDL_MOUSEMOTION)
	{
		if (setup->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
		{
			followPointX = *camX - *mouseX + 300;
			followPointY = *camY - *mouseY + 250;
			isFollowing = true;
		}
	}

	if (timeCheck + 10 < SDL_GetTicks() && isFollowing)
	{
		distance = getDistance(*camX, *camY, followPointX, followPointY);

		if (distance == 0)
			stopAnimation = true;
		else
			stopAnimation = false;

		if (distance > 15)
		{
			if (*camX != followPointX)
			{
				*camX = *camX - (((*camX - followPointX) / distance) * -1.5f);
			}

			if (*camY != followPointY)
			{
				*camY = *camY - (((*camY - followPointY) / distance) * -1.5f);
			}

			else
				isFollowing = false;
		}
		timeCheck = SDL_GetTicks();
	}
}

//calling our animation function and control function separately but using it as one function
void Character::Update()
{
	UpdateAnimation();
	UpdateControls();
}

//using math to get the distance between the X and Y axis to create a movement point
double Character::getDistance(int x1, int y1, int x2, int y2)
{
	double differenceX = x1 - x2;
	double differenceY = y1 - y2;
	double distance = sqrt((differenceX * differenceX) + (differenceY * differenceY));
	return distance;
}