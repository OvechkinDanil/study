#pragma once
#include "Brush.h"

class Eraser : public Brush
{
public:
	color_t color;
	Eraser()
	{
	}
	Eraser(size_items_t n_size, color_t n_color)
		:Brush(n_size)
	{
		color = n_color;
	}
};
