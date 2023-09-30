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
	wall(Vec2(0, 0), Graphics::ScreenWidth, Graphics::ScreenHeight),
	pad(Graphics::ScreenWidth / 2.0f, Graphics::ScreenHeight * 0.8f, 100.0f),
	ball(Vec2(500, 500))
{
	Color color_list[4] = { {20,30,140}, {20,130,140} ,{120,30,140},{120,130,140} };

	for (int j = 0; j < 4; j++) {
		for (int i = 20; i < Graphics::ScreenWidth; i += 60) {
			brick_list.push_back({ Vec2(i, 25*j +100), 50.0f, 20.0f, color_list[j]});
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
	float DT = FT.Mark();

	pad.update(DT,wall, wnd);
	ball.update(DT, wall);
	ball.touchPad(pad);

	for (Brick& b : brick_list) {

		b.touchBall(ball);
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
