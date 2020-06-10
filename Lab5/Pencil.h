#pragma once
#include "Brush.h"

class Pencil : public Brush
{
	public:
		Pencil()
		{
		}
		Pencil(size_items_t n_size, color_t n_color)
			:Brush(n_size, n_color)
		{
		}
};
