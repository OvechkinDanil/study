#pragma once
#include "glut.h"
#include <math.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

class GameObjects
{
	protected:
		float x;
		float y;
		float speed;
		GameObjects()
		{
			speed = 0;
			x = 0;
			y = 0;
		}
		GameObjects(float n_x, float n_y, float n_speed) : x(n_x), y(n_y), speed(n_speed)
		{
		}
	public:
		virtual const void Move(int direction) = 0;
		virtual const void Draw(void) = 0;
};
