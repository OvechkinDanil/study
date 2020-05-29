#pragma once
#include "GameObject.h"
typedef enum
{
	NULLBONUS,
	EXTRALIFE,
	RACKETWIDTHUP,
	RACKETWIDTHDOWN,
	BALLSPEEDUP
}bonus_t;

class Bonus : public GameObjects
{
private:
	float height;
	float width;
	bonus_t bonus;
public:
	Bonus()
	{
		height = 0;
		width = 0;
		bonus = NULLBONUS;
	}
	Bonus(float n_x, float n_y, float n_height, float n_width, float speed, bonus_t n_bonus)
		: GameObjects(n_x, n_y, speed)
	{
		height = n_height;
		width = n_width;
		bonus = n_bonus;
	}
	virtual const void Move(int direction) override;
	virtual const void Draw(void) override;
	float GetHeight(void)
	{
		return height;
	}
	float GetWidth(void)
	{
		return width;
	}
	float GetX(void)
	{
		return x;
	}
	float GetY(void)
	{
		return y;
	}
	bonus_t GetBonus(void)
	{
		return bonus;
	}
};
