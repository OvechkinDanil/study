#pragma once
#include "block.h"
#include "ball.h"
#include "bonus.h"
#include "racket.h"
#include <math.h>
#include <list>
using namespace std;

class Level
{
	private:
		Ball ball;
		Racket racket;
		vector< vector<Block> > blocks;
		short lives;
		list<Bonus> currentBonuses;
	public:
		Level()
		{
		}
		//void start();
		//void end();
		Level(string FileName);
		bool NoLives(void)
		{
			return lives < 0;
		}
		void DrawBlocks(void);
		void ChangeSystemPosition(int direction);
		void DrawBall(void);
		void DrawRacket(void);
		void ChangeActiveBall(void);
		bool isActiveBall(void);
		void MoveBall(void);
		void CheckCollisionBallRacket(void);
		void DrawLives(void);
		void DrawGameOver(void);
		void CheckCollisionBallBlock(void);
		bool CheckEndGame(void);
		void DrawWin(void);
		void DrawBonuses(void);
		void MoveBonuses(void);
		void CheckCollisionBonusRacket(void);
		void UseBonus(bonus_t bns);
};
