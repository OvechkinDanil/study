#include "ball.h"

const void Ball::Draw(void)
{
	glColor3f(0, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (float i = 0; i < 2 * PI; i += PI / 15)
	{
		glVertex2f(x + radius * sin(i), y + radius * cos(i));
	}
	glEnd();
}
const void Ball::Move(int direction)
{
	x += speed_x;
	y += speed_y;
	if (x + radius >= 5.5)
	{
		speed_x *= -1;
		x = 5.5 - radius;
	}
	if (y + radius >= 4.0)
	{
		speed_y *= -1;
		y = 4.0 - radius;
	}
	if (x + radius <= -5.4)
	{
		speed_x *= -1;
		x = -5.4 + radius;
	}
}
void Ball::ChangePos(int direction, float speed)
{
	if (direction < 0)
		x = x - speed;
	else if (direction > 0)
		x = x + speed;
}
