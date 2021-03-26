#pragma once
#include "RectI.h"
#include"Vec2.h"
#include"Graphics.h"
#include"rng.h"


class Board
{


private:

	class Tile
	{
	public:

		enum class Type {

			empty,
			food,
			poison,
			obstacle

		};

		Tile() = default;
		Tile(RectI rect);
		void Draw(Graphics& gfx);
		void SpawnObject(Type object_type);
		RectI getRect();
		Type  getType();


	private:

		RectI rect;
		Type eType;

	};

public:


	
	Board(RectI field);
	void Draw(Graphics& gfx);
	void Update();
	bool bIsFood(Tile& tile);
	Tile& tileAt(Vec2& pos);
	



   static Vec2 Board2Screen(const Vec2& pos,Board& brd);
   static int GetTileSize();
   static int Get_width();
   static int Get_height();

  


private:

	RectI field;
	static constexpr int TILE_SIZE =15;
	const static  int width = 30;
	const static  int height = 30; 
	const static  int nTILES_MAX = height * width;
	Tile tiles[nTILES_MAX];


};
