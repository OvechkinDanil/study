#pragma once
#include "Brush.h"

class Eraser : public Brush
{
public:
	Eraser()
	{
	}
	Eraser(size_items_t n_size, color_t n_color)
		:Brush(n_size, n_color)
	{

	}
};
