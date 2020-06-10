#pragma once
#include "Menu.h"
void MenuItem::PrintItem(void* font)
{
	const char* c;
	double x, y;

	pos.RasterPos2f();
	for (auto c : item)
	{
		glutBitmapCharacter(font, c);
	}
}
MenuItem::MenuItem(double new_x, double new_y, string& cur_item)
{
	Position cur_pos(new_x, new_y);
	pos = cur_pos;
	item = cur_item;
}

void Menu::Print(void)
{
	for (MenuItem it : items)
		it.PrintItem(GLUT_BITMAP_HELVETICA_18);
}
void Menu::СheckButtom(bool& isMenu, int x, int y)
{
	int index = 1;
	int item_pixel_x, item_pixel_y;
	for (MenuItem it : items)
			{
				item_pixel_x = it.ConvertPosX();
				item_pixel_y = it.ConvertPosY();
				if (index == 1 && abs(item_pixel_x - x) < 60 && abs(item_pixel_y - y) < 50)
				{
					isMenu = false;
					break;
				}
				if (index == 2)
				{
					pixels = new GLbyte[640 * 480 * 3];
					glReadPixels(0, 0, 640, 480, GL_RGB, GL_UNSIGNED_BYTE, pixels);
				}
				if (index == 3)
				{
					glDrawPixels(640, 480, GL_RGB, GL_UNSIGNED_BYTE, pixels);
				}
				index++;
			}
}

void menuFunc(int value)
{
	switch (value)
	{
	case RED:
		glColor3f(1.0f, 0.0f, 0.0f);
		pencil.SetColor(RED);
		pencil.ChangeActive();
		break;

	case GREEN:
		glColor3f(0.0f, 1.0f, 0.0f);
		pencil.SetColor(GREEN);
		pencil.ChangeActive();
		break;

	case BLUE:
		glColor3f(0.0f, 0.0f, 1.0f);
		pencil.SetColor(BLUE);
		pencil.ChangeActive();
		break;

	case PURPLE:
		glColor3f(0.8f, 0.0f, 1.0f);
		pencil.SetColor(PURPLE);
		pencil.ChangeActive();
		break;

	case YELLOW:
		glColor3f(1.0f, 1.0f, 0.1f);
		pencil.SetColor(YELLOW);
		pencil.ChangeActive();
		break;

	case POINT:
		cSwitch = POINT;
		break;
	case LINE:
		cSwitch = LINE;
		break;

	case RECTANGLE:
		cSwitch = RECTANGLE;
		break;
	case CIRCLE:
		cSwitch = CIRCLE;
		break;
	case SMALLPEN:
		pencil.ChangeSize(SMALLPEN);
		cSwitch = PENCIL;
		break;
	case MEDIUMPEN:
		pencil.ChangeSize(MEDIUMPEN);
		cSwitch = PENCIL;
		break;
	case LARGEPEN:
		pencil.ChangeSize(LARGEPEN);
		cSwitch = PENCIL;
		break;
	case SMALLERASER:
		eraser.ChangeSize(SMALLERASER);
		cSwitch = ERASER;
		break;
	case MEDIUMERASER:
		eraser.ChangeSize(MEDIUMERASER);
		cSwitch = ERASER;
		break;
	case LARGEERASER:
		eraser.ChangeSize(LARGEERASER);
		cSwitch = ERASER;
		break;
	case EXIT:
		exit(0);
		break;
	}
}

void initMenu()
{
	int submenu1, submenu2, submenu3, submenu4;

	submenu1 = glutCreateMenu(menuFunc);
	glutAddMenuEntry("Red", RED);
	glutAddMenuEntry("Green", GREEN);
	glutAddMenuEntry("Blue", BLUE);
	glutAddMenuEntry("Purple", PURPLE);
	glutAddMenuEntry("Yellow", YELLOW);
	submenu2 = glutCreateMenu(menuFunc);
	glutAddMenuEntry("Point", POINT);
	glutAddMenuEntry("Line", LINE);
	glutAddMenuEntry("Rectangle", RECTANGLE);
	glutAddMenuEntry("Circle", CIRCLE);
	submenu3 = glutCreateMenu(menuFunc);
	glutAddMenuEntry("Small", SMALLPEN);
	glutAddMenuEntry("Medium", MEDIUMPEN);
	glutAddMenuEntry("Large", LARGEPEN);
	submenu4 = glutCreateMenu(menuFunc);
	glutAddMenuEntry("Small", SMALLERASER);
	glutAddMenuEntry("Medium", MEDIUMERASER);
	glutAddMenuEntry("Large", LARGEERASER);
	glutCreateMenu(menuFunc);
	glutAddSubMenu("Colours", submenu1);
	glutAddSubMenu("Pencil", submenu3);
	glutAddSubMenu("Eraser", submenu4);
	glutAddSubMenu("Shape", submenu2);
	glutAddMenuEntry("clearScreen", CLEARSCREEN);
	glutAddMenuEntry("exit", EXIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
