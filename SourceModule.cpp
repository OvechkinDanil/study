#include "Rendering.h"
#include "glut.h"
Menu menu;
int init = 0;
int deltaX = 60;
int deltaY = 50;
int WinW = 640;
int WinH = 480;
list<MenuItem> curItems;

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
