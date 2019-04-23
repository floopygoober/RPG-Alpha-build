#ifndef SPRITE_H
#define SPRITE_H

#include "Libraries.h"

using namespace std;

class Sprite
{
public:
	//constructors and deconstructors
	Sprite(SDL_Renderer* passRenderer, string getFile, int x, int y, int w, int h, float *cameraX, float *cameraY);
	~Sprite();

	//drawing function for our scene 
	void Draw();
	//steady draw function to control camera and movement
	void DrawSteady();

	//variables for position
	void SetY(float Y);
	void SetX(float X);
	void SetSprite(float X, float Y);
	void SetPos(float X, float Y);
	void SetHeight(int H);
	void SetWidth(int W);
	void SetupAnimation(int frameAmountX, int frameAmountY);
	void PlayAnimation(int beginFrame, int endFrame, int row, float speed);

	//accessors for our height and width
	inline int getHeight() { return rectangle.h; }
	inline int getWidth() { return rectangle.w; }

	//using float for our camera and movement to keep it from being a static camera
	inline float getY() { return y_Position; }
	inline float getX() { return x_Position; }

private:
	//private variables to keep the vars protected
	SDL_Rect camera;

	float *camX;
	float *camY;
	float x_Position;
	float y_Position;
	float spriteOriginX;
	float spriteOriginY;

	SDL_Texture* image;
	SDL_Rect rectangle;
	SDL_Rect imageCrop;

	int imageWidth;
	int imageHeight;
	int framesOnX;
	int framesOnY;
	int currentFrame;
	int AnimationTimeCheck;

	SDL_Renderer* renderer;
};

#endif