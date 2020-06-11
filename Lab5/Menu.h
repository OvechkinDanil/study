#pragma once

#include <iostream>
#include <glut.h>
#include <list>
#include <math.h>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
menu_items_t cSwitch;
bool isMenu;
int WinW = 640;
int WinH = 480;
int formerX = -1;
int formerY = -1;
bool index = true;
Pencil pencil(SMALLPEN, RED);
Eraser eraser(SMALLERASER);
extern GLbyte* pixels;

typedef enum
{
	POINT = 6,
	LINE,
	RECTANGLE,
	CIRCLE,
	CLEARSCREEN,
	ERASER,
	PENCIL,
	EXIT,
}menu_items_t;
typedef enum
{
	SMALLPEN = 14,
	MEDIUMPEN,
	LARGEPEN,
	SMALLERASER,
	MEDIUMERASER,
	LARGEERASER
}size_items_t;

typedef enum
{
	RED,
	GREEN,
	BLUE,
	PURPLE,
	YELLOW,
	BLACK
}color_t;


class Position
{
private:
	double x;
	double y;
public:
	Position(void) { x = 0.0, y = 0.0; }
	Position(double new_x, double new_y) { x = new_x; y = new_y; }
	double x_toPixel(void) { return (int)(5.5 + x) * 640 / 11; }
	double y_toPixel(void) { return (int)(4.1 - y) * 480 / 8.2; }
	//double GetX(void) { return x; }
	//double GetY(void) { return y; }
	void RasterPos2f(void) { glRasterPos2f(x, y); }
};

class MenuItem
{
private:
	Position pos;
	string item;
public:
	MenuItem(double new_x, double new_y, string& cur_item);
	void PrintItem(void* font);
	string& GetItemName() { return item; }
	//double GetPosX() { return pos.GetX(); }
	//double GetPosY() { return pos.GetY(); }
	double ConvertPosX(void) { return pos.x_toPixel(); }
	double ConvertPosY(void) { return pos.y_toPixel(); }
};
class Menu
{
private:
	list<MenuItem> items;
public:
	void Print();
	void СheckButtom(bool& isMenu, int x, int y);
	void AddNewMenuItem(MenuItem new_item) { items.push_back(new_item); }
};

void menuFunc(int value);

void initMenu();
