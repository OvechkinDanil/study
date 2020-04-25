#include <glut.h>
#include <math.h>
#include "glut.h"
#include <list>

class Point 
{
	private:
		double x;
		double y;
		double radius;
	public:
		Point(void);
		Point(double xvalue, double yvalue, double radiusval)
		{
			x = xvalue;
			y = yvalue;
			radius = radiusval;
		}
		Point go_right(double delta);
		Point go_left(double delta);
		Point go_up(double delta);
		Point go_down(double delta);
		void DrawPoint(int iter);
		Point operator+(const Point& right)
		{
			Point temp;
			temp.x = this->x + right.x;
			temp.y = this->y + right.y;
			temp.radius = this->radius;
			return temp;
		}
		Point operator-(const Point& right)
		{
			Point temp;
			temp.x = this->x - right.x;
			temp.y = this->y - right.y;
			temp.radius = this->radius;
			return temp;
		}
};


class Trace
{
	private:
		std::list<Point> points;
		double speed;
	public:
		Trace(void);
		std::list<Point>&GetListOfPoints();
		double GetSpeed();
};

Trace trace;

Point::Point(void)
{
	x = 0.0;
	y = 0.0;
	radius = 0.1;
}
Point Point::go_right(double delta)
{
	Point current_pnt;
	Point deltaPoint(delta, 0, 0);
	current_pnt = *this + deltaPoint;
	return current_pnt;
}
Point Point::go_left(double delta)
{
	Point current_pnt;
	Point deltaPoint(delta, 0, 0);
	current_pnt = *this - deltaPoint;
	return current_pnt;
}
Point Point::go_up(double delta)
{
	Point current_pnt;
	Point deltaPoint(0, delta, 0);
	current_pnt = *this + deltaPoint;
	return current_pnt;
}
Point Point::go_down(double delta)
{
	Point current_pnt;
	Point deltaPoint(0, delta, 0);
	current_pnt = *this - deltaPoint;
	return current_pnt;
}
void Point::DrawPoint(int iter)
{
	glBegin(GL_POLYGON);
	for (float i = 0; i < 2 * 3.14; i += 3.14 / 15)
	{
		glVertex2f(x + radius * (1 + 0.08 * iter) * sin(i), y + radius * (1 + 0.08 * iter) * cos(i));
	}
	glEnd();
}
std::list<Point>& Trace::GetListOfPoints()
{
	return points;
}
double Trace::GetSpeed()
{
	return speed;
}
Trace::Trace(void)
{
	Point pnt;
	points.push_front(pnt);
	speed = 0.1;
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
	int i = 1;
	Point current_pnt;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);

	if (trace.GetListOfPoints().size() == 0)
	{
		Point pnt;
		trace.GetListOfPoints().push_front(pnt);
		glColor3f(0, 0.5, 0.5);
		pnt.DrawPoint(i);
		glutSwapBuffers();
		return;
	}
	if (trace.GetListOfPoints().size() > 10)
	{
		trace.GetListOfPoints().pop_back();
	}

	glColor3f(0, 0.5, 0.5);
	current_pnt = trace.GetListOfPoints().front();
	current_pnt.DrawPoint(i);
	trace.GetListOfPoints().pop_front();
	trace.GetListOfPoints().push_back(current_pnt);

	while (i < trace.GetListOfPoints().size())
	{
		current_pnt = trace.GetListOfPoints().front();
		glColor4f(0.5, 0.5, 0.5, 1.0 - i * 0.1);
		current_pnt.DrawPoint(i);
		trace.GetListOfPoints().pop_front();
		trace.GetListOfPoints().push_back(current_pnt);
		i++;
	}
	glutSwapBuffers();
}
void processSpecialKeys(int key, int x, int y)
{
	Point current_pnt, first_pnt;

	first_pnt = trace.GetListOfPoints().front();
	switch (key) {
	case GLUT_KEY_RIGHT:
	{
		current_pnt = first_pnt.go_right(trace.GetSpeed());
		break;
	}
	case GLUT_KEY_LEFT:
	{
		current_pnt = first_pnt.go_left(trace.GetSpeed());
		break;
	}
	case GLUT_KEY_UP:
	{
		current_pnt = first_pnt.go_up(trace.GetSpeed());
		break;
	}
	case GLUT_KEY_DOWN:
	{
		current_pnt = first_pnt.go_down(trace.GetSpeed());
		break;
	}
	}
	trace.GetListOfPoints().push_front(current_pnt);
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
