#include "Shapes.h"

class Rectangle : public Figures
{
protected:
	int x;
	int y;
	Rectangle()
	{
	}
	virtual void Draw(int x, int y) const override;
};
