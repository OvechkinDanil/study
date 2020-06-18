#include "Rectangle.h"
void  DrawPoint(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2f((x - WinW / 5.55) / (WinW / 5.55),
		-(y - WinH / 4.15) / (WinH / 4.15));
	glEnd();
	glFlush();
}
void  Rectangle::Draw(int x, int y) const
{
	int x0 = x, y0 = y, x1 = formerX, y1 = formerY;

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
