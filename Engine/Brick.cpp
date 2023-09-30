#include "Brick.h"

Brick::Brick(Vec2 position, float width, float height, Color c)
{
	box = Rect(position, width, height, c);
}

void Brick::draw(Graphics& gfx)
{
	box.draw(gfx);
}

bool Brick::touchBall(Ball& ball)
{
	
	Vec2 a = box.RectOverlap(ball.box);

	if(a.x || a.y){
	
		if (abs(a.x) > abs(a.y)) {
			a.x = 0;
			ball.vel.y = -ball.vel.y;
		}
		else {
			a.y = 0;
			ball.vel.x = -ball.vel.x;
		}
	
		ball.box.move(a);
	
		box.toggle_active();
	
	}
	return false;
}

bool Brick::is_active()
{
	return box.is_active();
}

void Brick::toggle_active()
{
	box.toggle_active();
}
