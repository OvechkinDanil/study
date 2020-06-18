#include "Point.h"
void  Point::Draw(int x, int y) const
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
