#include "bonus.h"

const void Bonus::Draw(void)
{
	
	switch (bonus)
	{
		case EXTRALIFE:
		{
			glColor3f(1.0, 0.0, 0.0);
			break;
		}
		case RACKETWIDTHUP:
		{
			glColor3f(0.3, 0.2, 0.6);
			break;
		}
		case RACKETWIDTHDOWN:
		{
			glColor3f(0.4, 0.6, 0.2);
			break;
		}
		case BALLSPEEDUP:
		{
			glColor3f(0.2, 0.2, 0.2);
			break;
		}
	}
	glBegin(GL_QUADS);
		glVertex2f(x - width / 2, y + height / 2);
		glVertex2f(x + width / 2, y + height / 2);
		glVertex2f(x + width / 2, y - height / 2);
		glVertex2f(x - width / 2, y - height / 2);
	glEnd();
}
const void Bonus::Move(int direction)
{
	y -= speed;
}
