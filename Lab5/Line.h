#include "Shapes.h"

class Line : public Figures
{
protected:
	int x;
	int y;
	Line()
	{
	}
	virtual void Draw(int x, int y) const override;
};
