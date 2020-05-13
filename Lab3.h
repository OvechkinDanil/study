#pragma once
#include <list>
using namespace std;

class Position
{
	private:
		double x;
		double y;
	public:
		Position(void);
		Position(double new_x, double new_y);
		double GetX(void);
		double GetY(void);
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
		list<MenuItem>& GetSubMenu();
		Position GetPos();
		MenuItem* GetParent(void);
		void PrintItem(void* font);
		string& GetItemName();
		int GetId();
		void AddSubMenuItems(list<MenuItem> nlist);
};
class Menu
{
	private:
		list<MenuItem> items;
	public:
		list<MenuItem>& GetMenuItems();
		void AddNewMenuItem(MenuItem new_item);
};
