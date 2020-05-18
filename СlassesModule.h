
#include <iostream>
#include <glut.h>
#include <list>
#include <math.h>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;



class Position
{
	private:
		double x;
		double y;
	public:
		Position(void) { x = 0.0, y = 0.0; }
		Position(double new_x, double new_y) { x = new_x; y = new_y; }
		double x_toPixel(void) { return (int)(5.5 + x) * WinW / 11; }
		double y_toPixel(void) { return (int)(4.1 - y) * WinH / 8.2; }
		void RasterPos2f(void) { glRasterPos2f(x, y); }
};

class MenuItem
{
	private:
		list<MenuItem> subMenu;
		MenuItem* parent;
		Position pos;
		string item;
		int id;
	public:
		MenuItem(MenuItem* npar, double new_x, double new_y, string& cur_item, int cur_id);
		list<MenuItem>& GetSubMenu()
		{
			return subMenu;
		}
		MenuItem* GetParent(void){ return parent; }
		void PrintItem(void* font);
		string& GetItemName() { return item; }
		int GetId() { return id; }
		void AddSubMenuItems(list<MenuItem> nlist) { subMenu = nlist; }
		double ConvertPosX(void) { return pos.x_toPixel(); }
		double ConvertPosY(void) { return pos.y_toPixel(); }
};
class Menu
{
	private:
		list<MenuItem> items;
	public:
		list<MenuItem>& GetMenuItems() { return items; }
		void AddNewMenuItem(MenuItem new_item) { items.push_back(new_item); }
};
