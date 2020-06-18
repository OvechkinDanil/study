#include "Menu.h"

Menu menu;
int init = 0;
int deltaX = 60;
int deltaY = 50;
float zoom = 10.0f;


void reshape(int w, int h) {

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
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, zoom,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);
	if (!init)
	{
		string newStr = "New";
		string openStr = "Open";
		string saveStr = "Save";
		MenuItem New(0.0, 0.0, newStr);
		MenuItem Open(0.0, -1.0, openStr);
		MenuItem Save(0.0, -2.0, saveStr);
		menu.AddNewMenuItem(New);
		menu.AddNewMenuItem(Open);
		menu.AddNewMenuItem(Save);
		init = 1;
		isMenu = true;
	}
	if (isMenu)
	{
		menu.Print();
	}
	glFlush();
}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q':
		zoom += 2;
		break;
	case 'a':
		zoom -= 2;
		break;
	default:
		break;
	}
}

void special(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		glColor3f(0.0f, 0.0f, 1.0f);
		break;

	case GLUT_KEY_RIGHT:
		glColor3f(1.0f, 0.0f, 0.0f);
		break;

	default:
		break;
	}
}

void mouse(int btn, int state, int x, int y) {
	if (isMenu && btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		menu.СheckButtom(isMenu, x, y);
	}
	else if (!isMenu)
	{
		switch (btn) {

		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN) 
			{
				figure->Draw(x,y);
			}

			break;

		}
	}
}
void motion(int x, int y) 
{
	point.Draw(x, y);
}

void timerRedisplay(int value) 
{
	glutTimerFunc(32, timerRedisplay, 0);
	display();
}

void glutCallbacks() 
{
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Paint");
	glutReshapeFunc(reshape);
	glutCallbacks();
	initMenu();


	glutMainLoop();

	return(0);
}
