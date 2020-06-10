#include "Shapes.h"

void drawPoint(int x, int y)
{
	if (pencil.isActive())
	{
		pencil.SetSize();
	}
	else if (eraser.isActive())
	{
		glColor3f(0.0f, 0.0f, 0.0f);
		eraser.SetSize();
	}
	glBegin(GL_POINTS);
	glVertex2f((x - WinW / 5.55) / (WinW / 5.55),
		-(y - WinH / 4.15) / (WinH / 4.15));
	glEnd();
	glFlush();
}


void drawLine(int x0, int y0, int x1, int y1)
{
	if (x0 == x1) {
		if (y0 < y1) {
			while (y0 < y1) {
				drawPoint(x0, y0 + 1);
				y0 = y0 + 1;
			}
		}
		else if (y1 < y0) {
			while (y1 < y0) {
				drawPoint(x0, y1 + 1);
				y1 = y1 + 1;
			}
		}
	}

	else
	{
		glPointSize(5);
		glBegin(GL_POINTS);

		float deltax = x1 - x0;
		float deltay = y1 - y0;
		float error = 0.0f;
		float deltaerr = fabs(deltay / deltax);
		int y = y0;

		bool checkifIncrease = (x1 >= x0) ? true : false;
		for (int x = x0; (checkifIncrease) ? (x < x1) : (x > x1); (checkifIncrease) ? (x++) : (x--))
		{
			glVertex2f((x - WinW / 5.5) / (WinW / 5.5),
				-(y - WinH / 4.15) / (WinH / 4.15));

			error = error + deltaerr;
			while (error >= 0.5)
			{
				glVertex2f((x - WinW / 5.5) / (WinW / 5.5),
					-(y - WinH / 4.15) / (WinH / 4.15));
				y = y + (y1 - y0) / abs(y1 - y0);

				error = error - 1.0f;
			}
		}
		glEnd();
		glFlush();
	}
}

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
void drawRectangle(int x1, int y1, int x0, int y0)
{


	drawLine(x0, y0, x1, y0);
	drawLine(x0, y0, x0, y1);
	drawLine(x1, y0, x1, y1);
	drawLine(x0, y1, x1, y1);

	if (y0 < y1) {
		while (y0 < y1) {

			drawPoint(x0, y0);
			drawPoint(x1, y0);
			y0 = y0 + 1;
		}
	}

	else if (y1 < y0) {
		while (y1 < y0) {

			drawPoint(x0, y1);
			drawPoint(x1, y1);
			y1 = y1 + 1;
		}
	}
}
void drawCircle(int toX, int toY)
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
