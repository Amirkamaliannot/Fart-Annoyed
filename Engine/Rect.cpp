#include "Rect.h"

Rect::Rect(Vec2& start, float width, float height, Color c_)
{
	top = start.y;
	bottom = start.y + height;
	left = start.x;
	right = start.x + width;

	half_width = width / 2;
	half_height = height / 2;

	c = c_;

	center = Vec2(start.x + half_width, start.y+ half_height);
}

void Rect::rebound_left(float changes)
{
	left -= changes;
	half_width += changes / 2.0f;
	center.x -= changes / 2.0f;
}
void Rect::rebound_right(float changes)
{
	right += changes;
	half_width += changes / 2.0f;
	center.x += changes / 2.0f;
}
void Rect::rebound_top(float changes)
{
	top -= changes;
	half_height += changes / 2.0f;
	center.y -= changes / 2.0f;
}
void Rect::rebound_bottom(float changes)
{
	bottom += changes;
	half_height += changes / 2.0f;
	center.y += changes / 2.0f;
}


void Rect::rebound_width(float changes)
{
	left -= changes/ 2.0f;
	right += changes/ 2.0f;
	half_height += changes / 2.0f;
}
void Rect::rebound_height(float changes)
{
	top -= changes/ 2.0f;
	bottom += changes/ 2.0f;
	half_height += changes/ 2.0f;
}

void Rect::move(Vec2& move_by)
{
	top += move_by.y;
	bottom += move_by.y;

	left += move_by.x;
	right += move_by.x;
	center += move_by;
}

void Rect::color(Color new_c)
{
	c = new_c;
}

Vec2 Rect::RectOverlap(Rect& rhs)
{
	if (active) {

		bool horizontalOverlap = (left < rhs.right) && (right > rhs.left);
		bool verticalOverlap = (top < rhs.bottom) && (bottom > rhs.top);
		if (horizontalOverlap && verticalOverlap) 
		{
			float horizontal_left = rhs.right - left;
			float horizontal_right = right - rhs.left;
			float vertical_top = rhs.bottom - top ;
			float vertical_bottom = bottom - rhs.top;

			
			Vec2 a = { min(horizontal_left, horizontal_right), min(vertical_bottom, vertical_top) };

			float horizontal;
			if( horizontal_right > horizontal_left){
			
				horizontal = -horizontal_left;
			}
			else {

				horizontal = horizontal_right;
			}
			
			float vertical;
			if( vertical_top > vertical_bottom){
			
				vertical = vertical_bottom;
			}
			else {

				vertical = -vertical_top;
			}

			return Vec2(horizontal, vertical);
		};
	}

	return Vec2(0.0f, 0.0f);
}


void Rect::draw(Graphics& gfx)
{
	if(active){
		gfx.DrawRect(left, top, right, bottom, c);
	}
}

bool Rect::is_active() const
{
	return active;
}

void Rect::toggle_active()
{
	active = !active;
}

float Rect::get_right()
{
	return right;
}
float Rect::get_half_width()
{
	return half_width;
}
float Rect::get_top()
{
	return top;
}
float Rect::get_bottom()
{
	return bottom;
}
float Rect::get_left()
{
	return left;
}
