#include "Level.h"
int row = 0, col = 0;
block_t DetermineTypeBlock(int block, bonus_t& bonustype)
{
	int blocktypeInt = block / 10;
	block_t blocktype;
	int bonusInt = block % 10;
	switch (blocktypeInt)
	{
		case 1:
			blocktype = WEAK;
			break;
		case 2:
			blocktype = MIDDLE;
			break;
		case 3:
			blocktype = STRONG;
			break;
	}
	switch (bonusInt)
	{
	case 0:
		bonustype = NULLBONUS;
		break;
	case 1:
		bonustype = EXTRALIFE;
		break;
	case 2:
		bonustype = RACKETWIDTHUP;
		break;
	case 3:
		bonustype = RACKETWIDTHDOWN;
		break;
	case 4:
		bonustype = BALLSPEEDUP;
		break;
	}
	return blocktype;
}
Block** CreateBlocks(string FileName)
{
	ifstream in(FileName);
	int blocktypeInt;
	int m = 0, n = 0;
	Block** blocks;
	block_t typeBlock;
	bonus_t typeBonus;
	in >> m;
	in >> n;
	row = m;
	col = n;
	blocks = new Block * [m];
	for (int i = 0; i < n; i++) blocks[i] = new Block[n];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			in >> blocktypeInt;
			typeBlock = DetermineTypeBlock(blocktypeInt, typeBonus);
			Block blk(0.0, 0.0, 0.0, 0.5, 0.8, typeBlock, typeBonus, i, j);
			blocks[i][j] = blk;
		}
	
	return blocks;
}
Level::Level(string FileName)
{
	Ball newBall(0.0, -3.15, 0.15, 0.15);
	Racket newRacket(0.0, -3.5, 2.0, 0.3, 0.3);
	ball = newBall;
	racket = newRacket;
	lives = 3;
	blocks = CreateBlocks(FileName);		
}
void Level::DrawBlocks(void)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			blocks[i][j].Draw();
		}
}
void Level::ChangeSystemPosition(int direction)
{
	racket.Move(direction);
	if (!ball.isActive())
	{
		float rac_speed = racket.GetSpeed();
		ball.ChangePos(direction, rac_speed);
	}
}
void Level::DrawBall(void)
{
	ball.Draw();
}
void Level::DrawRacket(void)
{
	racket.Draw();
}
void Level::ChangeActiveBall(void)
{
	ball.ChangeActive();
}
bool Level::isActiveBall(void)
{
	return ball.isActive();
}
void Level::MoveBall(void)
{
	ball.Move(0);
}
void Level::CheckCollisionBallRacket(void)
{
	float ball_x = ball.GetX();
	float ball_y = ball.GetY();
	float ball_r = ball.GetRadius();
	float rac_x = racket.GetX();
	float rac_y = racket.GetY();
	float rac_h = racket.GetHeight();
	float rac_w = racket.GetWidth();
	if (fabs(ball_y - rac_y) < ball_r + rac_h/2 && fabs(ball_x - rac_x) < ball_r + rac_w / 2) // проверка на столкновение мяча и ракетки
	{
		ball.ChangeSpeedY();
	}
	else if (ball_y + ball_r <= -4.15) // проверка на вылет за пределы поля
	{
		lives--;
		ball.ChangeSpeedY();
		ball.ChangeActive();
		ball.GoToRacket(rac_x, rac_y + ball_r + rac_h / 2);
	}
}
void Level::DrawLives(void)
{
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(-4, -4.00);
	char livesChar = lives + '0';
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'L');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'I');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'V');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'S');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ':');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
	for (int i = 0; i < lives; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '*');
}
void Level::DrawGameOver(void)
{
	glColor3f(1.0, 0.0, 0.0);
	glRasterPos2f(0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'G');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'M');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'V');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'R');
}
void Level::CheckCollisionBallBlock(void)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			float ball_x = ball.GetX();
			float ball_y = ball.GetY();
			float ball_r = ball.GetRadius();
			float blk_w = blocks[i][j].GetWidth();
			float blk_h = blocks[i][j].GetHeight();
			float blk_x = -5.30 + (j + 1 / 2) * blk_w + 0.1;
			float blk_y = 4.10 - ((i + 1 / 2) * blk_h - 0.1);
			if (blocks[i][j].isActive() && fabs(ball_y - blk_y) < ball_r + blk_h / 2 && fabs(ball_x - blk_x) < ball_r + blk_w / 2 && ball_x >= blk_x - blk_w / 2 && ball_x <= blk_x + blk_w / 2) // проверка на столкновение мяча и блока
			{
				ball.ChangeSpeedY();
				blocks[i][j].ChangeHit();
				if (blocks[i][j].GetHit() == 0)
				{
					blocks[i][j].notActive();
					const bonus_t bonus = blocks[i][j].GetBonus();
					if (bonus != NULLBONUS)
					{
						Bonus bns(blk_x, blk_y, blk_h, blk_w, 0.2, bonus);
						currentBonuses.push_back(bns);
					}
				}
				return;
			}
		}
}
bool Level::CheckEndGame(void)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			if (blocks[i][j].isActive())
				return false;
			else
				continue;
		}
	return true;
}
void Level::DrawWin(void)
{
	glColor3f(0.0, 1.0, 0.0);
	glRasterPos2f(0.0, 0.0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'L');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'V');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'L');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ' ');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'D');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
}
void Level::DrawBonuses(void)
{
	if (!currentBonuses.empty())
	{
		for (Bonus bns : currentBonuses)
			bns.Draw();
	}
}
void Level::MoveBonuses(void)
{
	if (!currentBonuses.empty())
	{
		for (Bonus bns : currentBonuses)
			bns.Move(0);
	}
}
void Level::UseBonus(bonus_t bns)
{
	switch (bns)
	{
		case EXTRALIFE:
		{
			lives += 1;
			break;
		}
		case RACKETWIDTHUP:
		{
			racket.ChangeWidth(0.2);
			break;
		}
		case RACKETWIDTHDOWN:
		{
			racket.ChangeWidth(-0.2);
			break;
		}
		case BALLSPEEDUP:
		{
			ball.SpeedUp(0.1);
			break;
		}
	}
}
void Level::CheckCollisionBonusRacket(void)
{
	if (!currentBonuses.empty())
	{
		for (Bonus bns : currentBonuses)
		{
			float bns_x = bns.GetX();
			float bns_y = bns.GetY();
			float bns_h = bns.GetHeight();
			float bns_w = bns.GetWidth();
			float rac_x = racket.GetX();
			float rac_y = racket.GetY();
			float rac_h = racket.GetHeight();
			float rac_w = racket.GetWidth();
			if (fabs(bns_x - rac_x) < bns_w + rac_w && fabs(bns_y - rac_y) < bns_h + rac_h)
			{
				bonus_t bonus = bns.GetBonus();
				this->UseBonus(bonus);
			}
		}
	}
}
