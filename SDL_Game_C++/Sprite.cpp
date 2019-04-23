#include "Sprite.h"


//setting our sprites image, movement, origin, camera position, and using pointers to help define the values
Sprite::Sprite(SDL_Renderer* passRenderer, string getFile, int x, int y, int w, int h, float *cameraX, float *cameraY)
{

	renderer = passRenderer;
	image = NULL;
	image = IMG_LoadTexture(passRenderer, getFile.c_str());
	if (image == NULL)
	{
		cout << "Couldnt load" << getFile.c_str() << endl;
	}
	
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;
	
	SDL_QueryTexture(image, NULL, NULL, &imageWidth, &imageHeight);
	imageCrop.x = 0;
	imageCrop.y = 0;
	imageCrop.w = imageWidth;
	imageCrop.h = imageHeight;

	x_Position = x;
	y_Position = y;

	spriteOriginX = 0;
	spriteOriginY = 0;

	currentFrame = 0;

	framesOnX = 0;
	framesOnY = 0;

	camX = cameraX;
	camY = cameraY;

	camera.x = rectangle.x + *camX;
	camera.y = rectangle.y + *camY;
	camera.w = rectangle.w;
	camera.h = rectangle.h;
}

//setting the variables to parameters so we can call them using pointers for our animation
void Sprite::SetupAnimation(int frameAmountX, int frameAmountY)
{
	framesOnX = frameAmountX;
	framesOnY = frameAmountY;
}

//basic loop for frame check and positioning of sprite sheet
void Sprite::PlayAnimation(int beginFrame, int endFrame, int row, float speed)
{
	if (AnimationTimeCheck + speed < SDL_GetTicks())
	{
		if (endFrame <= currentFrame)
			currentFrame = beginFrame;
		else
			currentFrame++;

		imageCrop.x = currentFrame * (imageWidth / framesOnX);
		imageCrop.y = row * (imageHeight / framesOnY);
		imageCrop.w = imageWidth / framesOnX;
		imageCrop.h = imageHeight / framesOnY;

		AnimationTimeCheck = SDL_GetTicks();
	}
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(image);
}

//rendering our sprite to the screen and attaching him to our camera and sprite position
void Sprite::Draw()
{
	camera.x = rectangle.x - *camX;
	camera.y = rectangle.y - *camY;

	SDL_RenderCopy(renderer, image, &imageCrop, &camera);
}

//keeping camera focused on player
void Sprite::DrawSteady()
{
	SDL_RenderCopy(renderer, image, &imageCrop, &camera);
}

//setting position X
void Sprite::SetX(float X)
{
	x_Position = X;
	rectangle.x = int(x_Position - spriteOriginX);
}

//setting position Y
void Sprite::SetY(float Y)
{
	y_Position = Y;
	rectangle.y = int(y_Position - spriteOriginY);
}

//setting both rect positions to our sprite
void Sprite::SetPos(float X, float Y)
{
	x_Position = X;
	y_Position = Y;

	rectangle.x = int(x_Position - spriteOriginX);
	rectangle.y = int(y_Position - spriteOriginY);
}

void Sprite::SetSprite(float X, float Y)
{
	spriteOriginY = Y;
	spriteOriginX = X;

	SetPos(getX(), getY());
}

void Sprite::SetWidth(int W)
{
	rectangle.w = W;
}

void Sprite::SetHeight(int H)
{
	rectangle.h = H;
}