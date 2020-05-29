#pragma once
#include "GameObject.h"
class Racket : public GameObjects
{
private:
	float height;
	float width;
public:
	Racket()
	{
		height = 0;
		width = 0;
	}
	Racket(float n_x, float n_y, float n_width, float n_height, float speed)
		: GameObjects(n_x, n_y, speed)
	{
		width = n_width;
		height = n_height;
	}
	virtual const void Move(int direction) override;
	virtual const void Draw(void) override;
	float GetX(void) // без этого никак, так как мне нужно проверять столкновение мяча и ракетки, а они в разных классах
	{
		return x;
	}
	float GetY(void)
	{
		return y;
	}
	float GetHeight(void)
	{
		return height;
	}
	float GetWidth(void)
	{
		return width;
	}
	float GetSpeed(void)
	{
		return speed;
	}
	void ChangeWidth(float deltaSize)
	{
		width = width + deltaSize;
	}
};
