#pragma once
#include "Classes.h"
void MenuItem::PrintItem(void* font)
{
	const char* c;
	double x, y;
	x = pos.GetX();
	y = pos.GetY();
	glRasterPos2f(x, y);
	for (c = item.c_str(); *c != '\0'; c++)
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
