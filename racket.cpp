#include "racket.h"
const void Racket::Draw(void)
{
	glColor3f(0.3, 0.0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(x - width / 2, y + height / 2);
	glVertex2f(x + width / 2, y + height / 2);
	glVertex2f(x + width / 2, y - height / 2);
	glVertex2f(x - width / 2, y - height / 2);
	glEnd();
}
const void Racket::Move(int direction)
{
	if (direction < 0)
		x = x - speed;
	else if (direction > 0)
		x = x + speed;
}
