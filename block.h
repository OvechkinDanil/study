#ifndef BLOCK_H
#define BLOCK_H
#include "GameObject.h"
#include "bonus.h"
typedef enum
{
	WEAK = 1,
	MIDDLE,
	STRONG
}block_t;

class Block : public GameObjects
{
	private:
		float height;
		float width;
		int row, col;
		block_t typeBlock;
		bonus_t bonus;
		int curHit;
		bool active;
	public:
		Block()
		{
		}
		Block(float n_x, float n_y, float n_speed, float n_height, float n_width, block_t n_typeBlock, bonus_t n_bonus, int n_row, int n_col)
			: GameObjects(n_x, n_y, n_speed)
		{
			height = n_height;
			width = n_width;
			typeBlock = n_typeBlock;
			curHit = typeBlock;
			bonus = n_bonus;
			active = true;
			row = n_row;
			col = n_col;
		}
		virtual const void Move(int direction) override;
		//virtual const void Collision(void) override;
		virtual const void Draw(void);
		float GetWidth()
		{
			return width;
		}
		float GetHeight()
		{
			return height;
		}
		void notActive()
		{
			active = false;
		}
		void ChangeHit()
		{
			curHit--;
		}
		int GetHit()
		{
			return curHit;
		}
		bool isActive()
		{
			return active;
		}
		bonus_t GetBonus()
		{
			return bonus;
		}
};

#endif
