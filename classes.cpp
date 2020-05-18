#pragma once
#include "Classes.h"
void MenuItem::PrintItem(void* font)
{
	const char* c;
	double x, y;
	
	pos.RasterPos2f();
	for (auto c : item)
	{
		glutBitmapCharacter(font, *c);
	}
}
MenuItem::MenuItem(MenuItem* npar, double new_x, double new_y, string& cur_item, int cur_id)
{
	parent = npar;
	Position cur_pos(new_x, new_y);
	pos = cur_pos;
	item = cur_item;
	id = cur_id;
}