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
		void SetEmpty(Tile& tile);
		RectI getRect();
		Type  getType();
		
	private:

		RectI rect;
		Type eType;
		

	};

public:

	Board(RectI field,int width,int height,int nPoison);
	~Board();

	void Draw(Graphics& gfx);
	
	bool IsFood(Tile& tile);
	bool IsPoison(Tile& tile);
	Tile& tileAt(Vec2& pos);
	void restartTile(Tile& tile);
	void RestartBoard();

   static Vec2 Board2Screen(const Vec2& pos,Board& brd);
   static Vec2 Board2Screen(const Vec2& pos, Board* pBrd);
   static constexpr int GetTileSize();
    int Get_width();
    int Get_height();
   
   RectI GetField()const;

private:

	RectI field;
	static constexpr int TILE_SIZE =15;
	int width;
	int height;
	int nPoison;
	int nTILES_MAX = height * width;
	Tile* tiles= nullptr;

};
