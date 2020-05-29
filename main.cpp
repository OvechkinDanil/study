#include "Level.h"

int win, lose;
Level level;
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
void render(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(0.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f);


	level.DrawBlocks();
	level.DrawBall();
	level.DrawRacket();
	level.DrawLives();
	level.DrawBonuses();
	if (win == 1)
		level.DrawWin();
	if (lose == 1)
		level.DrawGameOver();
	glutSwapBuffers();
}
void processSpecialKeys(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_RIGHT:
	{
		level.ChangeSystemPosition(1);
		break;
	}
	case GLUT_KEY_LEFT:
	{

		level.ChangeSystemPosition(-1);
		break;
	}
	}
}
void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 32)
		level.ChangeActiveBall();
	if (key == 27)
	{
		level.ChangeActiveBall();
	}

}
void Timer(int value)
{
	render();
	if (level.isActiveBall() && !level.NoLives())
	{
		level.MoveBall();
		level.MoveBonuses();
		level.CheckCollisionBallRacket();
		level.CheckCollisionBallBlock();
		level.CheckCollisionBonusRacket();
		if (level.CheckEndGame())
		{
			win = 1;
			level.ChangeActiveBall();
		}
	}
	if (level.NoLives())
	{
		lose = 1;
		level.ChangeActiveBall();
	}
	glutTimerFunc(33, Timer, 0);
}
void Init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0, 640, 480, 0, 1, 0);
}
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Arcanoid");

	Level lvl1("level1.txt");
	level = lvl1;
	glutReshapeFunc(reshape);
	glutDisplayFunc(render);
	glutTimerFunc(33, Timer, 0);
	glutIdleFunc(render);
	glutSpecialFunc(processSpecialKeys);
	glutKeyboardFunc(processNormalKeys);

	glutMainLoop();
}
