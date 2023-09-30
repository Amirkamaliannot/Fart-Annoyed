#pragma once


#include "Vec2.h"
#include "Rect.h";
#include "Graphics.h"
#include "Pad.h"
#include "Colors.h"
#include "Ball.h"

class Brick {

public:

	Brick(Vec2 position, float width, float height, Color c);
	void draw(Graphics& gfx);

	bool touchBall(Ball& ball);

	bool is_active();

	void toggle_active();

private:


	Rect box;
	float speed = 200.0f;
};
