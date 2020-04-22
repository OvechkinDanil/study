#include <glut.h>
#include <math.h>
#include "glut.h"
#include <list>

class Point 
{
	public:
		double x;
		double y;
		double radius;

		Point go_right(Point &first_pnt, double delta);
		Point go_left(Point &first_pnt, double delta);
		Point go_up(Point &first_pnt, double delta);
		Point go_down(Point& first_pnt, double delta);
};

class Trace
{
	public:
		std::list<Point> points;
		double speed;
};

Trace trace;

Point Point::go_right(Point& first_pnt, double delta)
{
	Point current_pnt;
	current_pnt.x = first_pnt.x + delta;
	current_pnt.y = first_pnt.y;
	current_pnt.radius = first_pnt.radius;
	return current_pnt;
}
Point Point::go_left(Point& first_pnt, double delta)
{
	Point current_pnt;
	current_pnt.x = first_pnt.x - delta;
	current_pnt.y = first_pnt.y;
	current_pnt.radius = first_pnt.radius;
	return current_pnt;
}
Point Point::go_up(Point& first_pnt, double delta)
{
	Point current_pnt;
	current_pnt.y = first_pnt.y + delta;
	current_pnt.x = first_pnt.x;
	current_pnt.radius = first_pnt.radius;
	return current_pnt;
}
Point Point::go_down(Point& first_pnt, double delta)
{
	Point current_pnt;
	current_pnt.y = first_pnt.y - delta;
	current_pnt.x = first_pnt.x;
	current_pnt.radius = first_pnt.radius;
	return current_pnt;
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
void DrawPoint(Point pnt, int iter)
{
	glBegin(GL_POLYGON);
	for (float i = 0; i < 2 * 3.14; i += 3.14 / 15)
	{
		glVertex2f(pnt.x + pnt.radius * (1 + 0.08 * iter) * sin(i), pnt.y + pnt.radius * (1 + 0.08 * iter) * cos(i));
	}
	glEnd();
}
void render(void) {
	int i = 1;
	Point current_pnt;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	if (trace.points.size() == 0)
	{
		Point pnt = { 0.0, 0.0, 0.1 };
		trace.points.push_front(pnt);
		trace.speed = 0.1;
		glColor3f(0, 0.5, 0.5);
		DrawPoint(pnt, i);
		glutSwapBuffers();
		return;
	}
	if (trace.points.size() > 10)
	{
		trace.points.pop_back();
	}

	glColor3f(0, 0.5, 0.5);
	current_pnt = trace.points.front();
	DrawPoint(current_pnt, i);
	trace.points.pop_front();
	trace.points.push_back(current_pnt);

	while (i < trace.points.size())
	{
		current_pnt = trace.points.front();
		glColor4f(0.5, 0.5, 0.5, 1.0 - i * 0.1);
		DrawPoint(current_pnt, i);
		trace.points.pop_front();
		trace.points.push_back(current_pnt);
		i++;
	}
	glutSwapBuffers();
}
void processSpecialKeys(int key, int x, int y)
{
	Point current_pnt, first_pnt;

	first_pnt = trace.points.front();
	switch (key) {
	case GLUT_KEY_RIGHT:
	{
		current_pnt = first_pnt.go_right(first_pnt, trace.speed);
		break;
	}
	case GLUT_KEY_LEFT:
	{
		current_pnt = first_pnt.go_left(first_pnt, trace.speed);
		break;
	}
	case GLUT_KEY_UP:
	{
		current_pnt = first_pnt.go_up(first_pnt, trace.speed);
		break;
	}
	case GLUT_KEY_DOWN:
	{
		current_pnt = first_pnt.go_down(first_pnt, trace.speed);
		break;
	}
	}
	trace.points.push_front(current_pnt);
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
	glOrtho(0, 640, 480, 0, 1, 0);
}
int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Test");
	
	glutReshapeFunc(reshape);
	glutDisplayFunc(render);
	glutTimerFunc(33, Timer, 0);

	glutSpecialFunc(processSpecialKeys);

	glutMainLoop();
}
