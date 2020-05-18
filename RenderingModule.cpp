#include "Rendering.h"


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
			item_pixel_x = it.ConvertPosX();
			item_pixel_y = it.ConvertPosY();
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
