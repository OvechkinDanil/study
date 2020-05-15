#pragma once
#include "Classes.h"
#include "Parcing.h"
int x_toPixel(double cur_x);

int y_toPixel(double cur_y);

list<MenuItem> FindSubMenu(MenuItem* parent, string& str);

void reshape(int w, int h);

void reshape(int w, int h);

void render(void);

void MousePressed(int buttom, int state, int x, int y);
