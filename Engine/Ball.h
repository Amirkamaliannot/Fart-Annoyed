#pragma once
#include "Vec2.h"
#include "Rect.h";
#include "Graphics.h"
#include "Pad.h"
//#include "Brick.h"


class Ball {

public:

	Ball(Vec2 position);

	void update(float DT, Rect& Wall);

	void draw(Graphics& gfx);

	bool touchWall(Rect& Wall);
	bool touchPad(Pad& pad);
	//bool touchBrick(Brick& Brick);

	Rect box;
	Vec2 vel{ -10,-10};
private:

	static constexpr float size = 20.0f;



	float speed = 200.0f;
};
