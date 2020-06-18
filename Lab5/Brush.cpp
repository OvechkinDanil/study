#include "Brush.h"

const void Brush::SetSize()
{
	switch (size)
	{
		case SMALLPEN:
		case SMALLERASER:
			glPointSize(5);
			break;
		case MEDIUMPEN:
		case MEDIUMERASER:
			glPointSize(9);
			break;
		case LARGEPEN:
		case LARGEERASER:
			glPointSize(13);
			break;
	}
}
