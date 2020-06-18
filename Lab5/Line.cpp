#include "Line.h"
void  Line::Draw(int x, int y) const
{
	int x0 = x;
	int x1 = formerX;
	int y0 = y;
	int y1 = formerY;
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
