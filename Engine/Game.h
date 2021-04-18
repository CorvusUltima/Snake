/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Numbers.h"
#include "rng.h"
#include "FrameTimer.h"
#include "Vec2.h"
#include"Snake.h"
#include"assert.h"
#include"txtManipulation.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	~Game();
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void DestroyBoard();
	/********************************/
	/*  User Functions        */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
    FrameTimer ft;
	/********************************/
	Board* brd = nullptr;
	Snake* snake = nullptr;
	txtManipulation  txt;
	std::string string_width = txt.get_substring("SnakeGame.txt", "[BOARD DIMENSION]", 1);
	std::string string_width_number = txt.remove_all_non_numberCH(string_width);

	int width = std::stoi(string_width_number);//ok this is not working.... great let do this 
	int hight = std::stoi(txt.remove_all_non_numberCH ( txt.get_substring("SnakeGame.txt", "[BOARD DIMENSION]", 2)));
	int nPoison= std::stoi(txt.remove_all_non_numberCH(txt.get_substring("SnakeGame.txt", "[POISON]", 1)));
	
	
};