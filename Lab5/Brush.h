#pragma once
#include "Menu.h"



class Brush
{
protected:
	size_items_t size;
	color_t color;
	bool active;
	Brush()
	{
		
	}
	Brush(size_items_t n_size, color_t n_color) : size(n_size), color(n_color)
	{
		active = false;
	}
public:
	virtual const void SetColor(color_t n_color)
	{
		color = n_color;
	}
	virtual const void ChangeActive()
	{
		active = !active;
	}
	virtual const void ChangeSize(size_items_t n_size)
	{
		size = n_size;
	}
	virtual bool isActive()
	{
		return active;
	}
	virtual const void SetSize();
};
