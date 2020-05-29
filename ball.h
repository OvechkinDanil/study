#pragma once
#include "GameObject.h"
const double PI = 3.141592653589793;

class Ball : public GameObjects
{
private:
	float radius;
	float speed_x;
	float speed_y;
	bool active;
public:
	Ball()
	{
		radius = 0;
		speed_x = 0;
		speed_y = 0;
		active = false;
	}
	Ball(float n_x, float n_y, float n_radius, float speed)
		: GameObjects(n_x, n_y, speed)
	{
		radius = n_radius;
		speed_x = speed;
		speed_y = speed;
		active = false;
	}
	virtual const void Move(int direction) override;
	//virtual const void Collision(void) override;
	virtual const void Draw(void) override;
	bool isActive()
	{
		return active;
	}
	void ChangePos(int direction, float speed);
	void ChangeActive(void)
	{
		if (active)
		{
			active = false;
		}
		else
		{
			active = true;
		}
	}
	float GetX()
	{
		return x;
	}
	float GetY()
	{
		return y;
	}
	float GetRadius()
	{
		return radius;
	}
	void ChangeSpeedY()
	{
		speed_y *= -1;
	}
	void GoToRacket(float n_x, float n_y)
	{
		x = n_x;
		y = n_y;
	}
	void SpeedUp(float delta_speed)
	{
		if (speed_x <= 0)
			speed_x -= delta_speed;
		else if (speed_x > 0)
			speed_x += delta_speed;
		if (speed_y <= 0)
			speed_y -= delta_speed;
		else if (speed_y > 0)
			speed_y += delta_speed;
	}
};
