#include "Pad.h"

Pad::Pad(float _x, float _y, float _width)
{
	box = Rect{ Vec2(_x - _width / 2.0f, _y), _width, height };
}

void Pad::update(float DT, Rect& wall, MainWindow& wnd)
{

	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {

		box.move(Vec2{ 1,0 } * speed * DT);
	}	
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {

		box.move(Vec2{ -1,0 } *speed * DT);
	}	
	if (wnd.kbd.KeyIsPressed(VK_UP)) {

		box.move(Vec2{ 0,-1 } *speed * DT);
	}	
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {

		box.move(Vec2{ 0,1 } *speed * DT);
	}	
	touchWall(wall);
}

void Pad::draw(Graphics& gfx)
{
	box.draw(gfx);
}


bool Pad::touchWall(Rect& Wall)
{

	bool touch = false;
	if (box.get_left() < Wall.get_left())
	{
		box.move(Vec2{ Wall.get_left() - box.get_left() ,0.0f });
		touch = true;
	}
	if (box.get_right() > Wall.get_right())
	{
		box.move(Vec2{ Wall.get_right() - box.get_right() ,0.0f });
		touch = true;
	}
	if (box.get_top() < Wall.get_top())
	{
		box.move(Vec2{ 0.0f, Wall.get_top() - box.get_top() });
		touch = true;
	}
	if (box.get_bottom() > Wall.get_bottom())
	{
		box.move(Vec2{ 0.0f, Wall.get_bottom() - box.get_bottom() });
		touch = true;
	}

	if (touch) {
		return true;
	}
	return false;
}

float Pad::get_line_y()
{
	return box.get_top();
}
float Pad::get_line_left()
{
	return box.get_left();
}
float Pad::get_line_right()
{
	return box.get_right();
}

float Pad::get_width()
{
	return box.get_right() - box.get_left();
}



