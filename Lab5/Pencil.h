#pragma once
#include "Brush.h"

class Pencil : public Brush
{
	private:
		color_t color;
	public:
		Pencil()
		{
		}
		Pencil(size_items_t n_size, color_t n_color)
			:Brush(n_size)
		{
			color = n_color;
		}
		const void SetColor(color_t n_color)
		{
			color = n_color;
		}
};
