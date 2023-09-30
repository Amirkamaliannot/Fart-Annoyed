/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	SM(gfx),
	wall(Vec2(0, 0), Graphics::ScreenWidth, Graphics::ScreenHeight),
	pad(Graphics::ScreenWidth / 2.0f, Graphics::ScreenHeight * 0.8f, 100.0f),
	ball(Vec2(500, 500))
{
	Color color_list[4] = { {20,30,140}, {20,130,10 } ,{120,30,0},{120,130,140} };

	float start_x = (Graphics::ScreenWidth % (int)(brick_width + brick_padd))/2;

	for (int j = 0; j < 4; j++) {
		for (int i = start_x; i < Graphics::ScreenWidth - brick_width - brick_padd; i += brick_width+brick_padd) {

			brick_list.push_back({ Vec2(i, (brick_height + brick_padd) * j + 100.0f), brick_width, brick_height, color_list[j]});
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{

	if (check_start()) {

		if (win) 
		{
			SM.show_win();
		}
		else if(loss) 
		{

			SM.show_loss();

		}
		else if(!check_pause()) 
		{
			float DT = FT.Mark();

			pad.update(DT,wall, wnd);
			ball.update(DT, wall);
			ball.touchPad(pad);

			if (ball.touchGround(wall)) {
				loss = true;
			}

			int win_tmp = true;
			for (Brick& b : brick_list) {

				b.touchBall(ball);
				if (b.is_active()) {win_tmp = false;}
			}
			if (win_tmp) { win = true; }
		}
	}
}

void Game::ComposeFrame()
{
	pad.draw(gfx);
	ball.draw(gfx);
	
	for (Brick& b : brick_list) {

		b.draw(gfx);
	}
}


bool Game::check_start()
{
	if (!start) {
		SM.show_intro();
		if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
			start = true;
			FT.Mark();
		}
	}
	return start;
}
bool Game::check_pause()
{
	if (!pause) {
		if (wnd.kbd.KeyIsPressed(VK_ESCAPE)) {
			if (!isPressed_pause) {
				pause = true;
				isPressed_pause = true;
			}
		}
		else {
			isPressed_pause = false;
		}
	}
	else {

		if (wnd.kbd.KeyIsPressed(VK_ESCAPE)) {
			if (!isPressed_pause) {
				isPressed_pause = true;
				pause = false;
				FT.Mark();
			}
		}
		else {
			isPressed_pause = false;
		}
	}

	return pause;

}