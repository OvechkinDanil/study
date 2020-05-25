#pragma once
#include <iostream>

typedef enum
{
	EXTRAPOINTS,
	EXTRALIFE,
	RACKETWIDTHUP,
	RACKETWIDTHDOWN,
	BALLSPEEDUP,
	BALLSTRONG
}bonus_t;
typedef enum
{
	WEAK = 1,
	MIDDLE,
	STRONG
}block_t;

class GameObjects
{
	protected:
		float x;
		float y;
		float speed;
		GameObjects(float n_x, float n_y, float n_speed) : x(n_x), y(n_y), speed(n_speed)
		{
		}
	public:
		virtual const void Move() = 0;
		virtual const void Collision() = 0;
		virtual const void Draw() = 0;
};
class Racket : public GameObjects
{
	private:
		float height;
		float width;
	public:
		Racket(float n_x, float n_y, float n_width, float n_height, float speed)
			: GameObjects(n_x, n_y, speed)
		{
			width = n_width;
			height = n_height;
		}
		virtual const void Move() override;
		virtual const void Collision() override;
		virtual const void Draw() override;
};
class Ball : public GameObjects
{
	private:
		float radius;
	public:
		Ball(float n_x, float n_y, float n_radius, float speed)
			: GameObjects(n_x, n_y, speed)
		{
			radius = n_radius;
		}
		virtual const void Move() override;
		virtual const void Collision() override;
		virtual const void Draw() override;
};
class Block : public GameObjects
{
	private:
		float height;
		float width;
		block_t typeBlock;
	public:
		Block(float n_x, float n_y, float n_height, float n_width, float speed, block_t n_typeBlock)
			: GameObjects(n_x, n_y, speed)
		{
			height = n_height;
			width = n_width;
			typeBlock = n_typeBlock;
		}
		virtual const void Move() override;
		virtual const void Collision() override;
		virtual const void Draw() override;
};
class Bonus : public GameObjects
{
	private:
		float height;
		float width;
		bonus_t bonus;
	public:
		Bonus(float n_x, float n_y, float n_height, float n_width, float speed, bonus_t n_bonus)
			: GameObjects(n_x, n_y, speed)
		{
			height = n_height;
			width = n_width;
			bonus = n_bonus;
		}
		virtual const void Move() override;
		virtual const void Collision() override;
		virtual const void Draw() override;
};
