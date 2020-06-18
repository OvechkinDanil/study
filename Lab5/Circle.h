#include "Shapes.h"

class Circle : public Figures
{
protected:
	int x;
	int y;
	Circle()
	{
	}
	virtual void Draw(int x, int y) const override;
};
