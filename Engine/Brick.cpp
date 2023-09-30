#include "Brick.h"

Brick::Brick(Vec2 position, float width, float height, Color c)
{
	box = Rect(position, width, height, c);
}

void Brick::draw(Graphics& gfx)
{
	box.draw(gfx);
}
