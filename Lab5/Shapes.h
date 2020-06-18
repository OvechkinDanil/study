#include "Eraser.h"
#include "Pencil.h"

class Figures
{
protected:
	int x;
	int y;
	Figures()
	{
	}
	virtual void Draw(int x, int y) const = 0;
};

