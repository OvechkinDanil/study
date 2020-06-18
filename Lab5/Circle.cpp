#include "Circle.h"

float getRadius(int initX, int initY, int x, int y)
{
	return sqrt((y - initY) * (y - initY) + (x - initX) * (x - initX));
}
float cMXSX(float x)
{
	return ((float)x) / WinW * 11.0f - 5.5f;
}
float cMYSY(float y)
{
	return 4.15 - ((float)y) / WinH * 8.3f;
}
void  Circle::Draw(int x, int y) const
{
	glPointSize(5);
	glBegin(GL_POINTS);

	int radius = getRadius(formerX, formerY, toX, toY);
	int x0 = formerX;
	int y0 = formerY;
	int x = radius;
	int y = 0;
	int checkAfter2 = 1 - x;

	while (y <= x) {
		glVertex2f(cMXSX((float)x + x0), cMYSY((float)(y + y0)));
		glVertex2f(cMXSX((float)y + x0), cMYSY((float)(x + y0)));
		glVertex2f(cMXSX((float)-x + x0), cMYSY((float)(y + y0)));
		glVertex2f(cMXSX((float)-y + x0), cMYSY((float)(x + y0)));
		glVertex2f(cMXSX((float)-x + x0), cMYSY((float)(-y + y0)));
		glVertex2f(cMXSX((float)-y + x0), cMYSY((float)(-x + y0)));
		glVertex2f(cMXSX((float)x + x0), cMYSY((float)(-y + y0)));
		glVertex2f(cMXSX((float)y + x0), cMYSY((float)(-x + y0)));
		y++;
		if (checkAfter2 <= 0)
			checkAfter2 += 2 * y + 1;
		else {
			x--;
			checkAfter2 += 2 * (y - x) + 1;
		}
	}
	glEnd();
	glFlush();
	formerX = -1;
	formerY = -1;
}
