#include "block.h"

const void Block::Draw(void)
{
	switch (typeBlock)
	{
		case WEAK:
			glColor3f(0.1, 0.2, 0.8);
	}
	glBegin(GL_QUADS);
		if (active)
		{
			float delta = 0.1;
			glVertex2f(-5.30 + col * width + delta, 4.10 - (row * height + delta));
			glVertex2f(-5.30 + col * width + width - delta, 4.10 - (row*height + delta));
			glVertex2f(-5.30 + col * width + width - delta, 4.10 - (row * height + height - delta));
			glVertex2f(-5.30 + col * width + delta, 4.10 - (row * height + height - delta));
		}
	glEnd();
}
const void Block::Move(int direction)
{
}
