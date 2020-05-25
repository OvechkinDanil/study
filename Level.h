#pragma once
#include <iostream>
#include <string.h>
#include "GameObject.h"
#include <vector>
class Level
{
	private:
		Ball ball;
		Racket racket;
		std::vector<Bonus> Bonuses;
		std::vector<std::vector<Block>> blocks;
	public:
		void start();
		void end();
		Level(std::string FileName);
};
