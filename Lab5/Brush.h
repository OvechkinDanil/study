#pragma once
#include "Menu.h"



class Brush
{
protected:
	size_items_t size;
	bool active;
	Brush()
	{
		
	}
	Brush(size_items_t n_size) : size(n_size)
	{
		active = false;
	}
public:
	virtual void ChangeActive()
	{
		active = !active;
	}
	virtual void ChangeSize(size_items_t n_size)
	{
		size = n_size;
	}
	virtual bool isActive()
	{
		return active;
	}
	virtual void SetSize();
};
