#include "Shapes.h"

class Point : public Figures
{
protected:
	int x;
	int y;
	Point()
	{
	}
	virtual void Draw(int x, int y) const override;
};
