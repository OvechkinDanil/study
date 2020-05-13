#include <iostream>
#include "Lab3.h"
#include <glut.h>
#include <math.h>
#include "glut.h"
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

Menu menu;
int init = 0;
int deltaX = 60;
int deltaY = 50;
int WinW = 640;
int WinH = 480;
list<MenuItem> curItems;
int MenuItem::GetId(void)
{
	return id;
}
string& MenuItem::GetItemName(void)
{
	return item;
}
list<MenuItem>& MenuItem::GetSubMenu(void)
{
	return subMenu;
}
MenuItem* MenuItem::GetParent(void)
{
	return parent;
}
void MenuItem::AddSubMenuItems(list<MenuItem> nlist)
{
	subMenu = nlist;
}
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
Position MenuItem::GetPos(void)
{
	return pos;
}
Position::Position(void)
{
	x = 0.0;
	y = 0.0;
}
Position::Position(double new_x, double new_y)
{
	x = new_x;
	y = new_y;
}
double Position::GetX(void)
{
	return x;
}
double Position::GetY(void)
{
	return y;
}
MenuItem::MenuItem(MenuItem* npar, double new_x, double new_y, string& cur_item, int cur_id)
{
	parent = npar;
	Position cur_pos(new_x, new_y);
	pos = cur_pos;
	item = cur_item;
	id = cur_id;
}
list<MenuItem>& Menu::GetMenuItems()
{
	return items;
}
void Menu::AddNewMenuItem(MenuItem new_item)
{
	items.push_back(new_item);
}
int x_toPixel(double cur_x)
{
	return (int)(5.5 + cur_x) * WinW / 11;
}
int y_toPixel(double cur_y)
{
	return (int)(4.1 - cur_y) * WinH / 8.2;
}

void split(const string& str, vector<string>& tokens, const string& delimiters = " ")
{
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	string::size_type pos = str.find_first_of(delimiters, lastPos);
	tokens.push_back(str.substr(lastPos, pos - lastPos));
	lastPos = str.find_first_not_of(delimiters, pos);
	pos = str.size();
	tokens.push_back(str.substr(lastPos, pos));
}
list<MenuItem> FindSubMenu(MenuItem* parent, string& str)
{
	double x = 0, y = 3.8;
	vector<string> sub;
	list<MenuItem> listMenuItems;
	str.erase(0, 1);
	do
	{
		split(str, sub);
		list<MenuItem> subMenu;
		MenuItem it(parent, x, y, sub.front(), 0);
		if (sub.back()[0] == '[')
			it.AddSubMenuItems(FindSubMenu(&it, sub.back()));
		listMenuItems.push_back(it);
		str = sub.back();
		sub.clear();
		y -= 0.6;
	} while (str[0] != ']');
	return listMenuItems;
}
void TextParcing(string filename)
{
	int i;
	string str;
	double x = 0, y = 3.8;
	vector<string> s, submenu;
	ifstream input(filename);
	while (!input.eof())
	{
		std::getline(input, str);
		split(str, submenu, " ");
		MenuItem it(NULL, x, y, submenu.front(), 0);
		if (submenu.back()[0] == '[')
			it.AddSubMenuItems(FindSubMenu(&it, submenu.back()));
		menu.AddNewMenuItem(it);
		y -= 0.6;
	}
}
void reshape(int w, int h)
{
	if (h == 0)
		h = 1;
	float ratio = 1.0 * w / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, w, h, 0.0f, 0.0f, 0.0f);
	gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}
void render(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
	if (!init)
	{
		curItems = menu.GetMenuItems();
		init = 0;
	}
	for (MenuItem it : curItems)
		it.PrintItem(GLUT_BITMAP_HELVETICA_18);
	
	glutSwapBuffers();
}
void MousePressed(int buttom, int state, int x, int y)
{
	int item_pixel_x, item_pixel_y;
	if (buttom == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		for (MenuItem it : curItems)
		{
			item_pixel_x = x_toPixel(it.GetPos().GetX());
			item_pixel_y = y_toPixel(it.GetPos().GetY());
			if (abs(item_pixel_x - x) < deltaX && abs(item_pixel_y - y) < deltaY)
			{
				curItems = it.GetSubMenu();
				break;
			}
		}
	}
}
void Timer(int value)
{
	render();
	glutTimerFunc(33, Timer, 0);
}
void Init(void)	
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, WinW, WinH, 0, 1, 0);
}
int main(int argc, char** argv)
{
	TextParcing("test123.txt");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(WinW, WinH);
	glutCreateWindow("Test");

	glutReshapeFunc(reshape);
	glutDisplayFunc(render);
	glutTimerFunc(33, Timer, 0);
	
	glutMouseFunc(MousePressed);

	glutMainLoop();
}
