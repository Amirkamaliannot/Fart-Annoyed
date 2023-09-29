#pragma once
#include "Rect.h"
#include "MainWindow.h"
#include "Graphics.h"

class Pad {

public:
	Pad(float _x, float _y, float _width);

	void update(float DT, Rect& wall, MainWindow& wnd);
	void draw(Graphics& gfx);

	bool touchWall(Rect& Wall);

	Rect box;

private:


	float speed = 200;
	static constexpr float height = 10.0f;

};