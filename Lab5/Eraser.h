#pragma once
#include "Brush.h"

class Eraser : public Brush
{
public:
	color_t color;
	Eraser()
	{
	}
	Eraser(size_items_t n_size)
		:Brush(n_size)
	{
		color = BLACK;
	}
};
