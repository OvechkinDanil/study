
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
		double GetX(void) { return x; }
		double GetY(void) { return y; }
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
		Position GetPos() { return pos; }
		MenuItem* GetParent(void){ return parent; }
		void PrintItem(void* font);
		string& GetItemName() { return item; }
		int GetId() { return id; }
		void AddSubMenuItems(list<MenuItem> nlist) { subMenu = nlist; }
};
class Menu
{
	private:
		list<MenuItem> items;
	public:
		list<MenuItem>& GetMenuItems() { return items; }
		void AddNewMenuItem(MenuItem new_item) { items.push_back(new_item); }
};
