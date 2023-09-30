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

	float get_line_y();
	float get_line_left();
	float get_line_right();

	float get_width();


private:


	Rect box;
	float speed = 300.0f;
	static constexpr float height = 10.0f;

};