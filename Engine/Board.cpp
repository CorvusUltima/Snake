#include "Board.h"

Board::Tile::Tile(RectI rect)
	:
	rect(rect)	
{
	eType = Type::empty;
}

void Board::Tile::Draw(Graphics& gfx)
{

	
	switch (eType) 
	{
	case Type::empty:
		gfx.DrawRectEmpty(rect.left,
			rect.top,
			Board::TILE_SIZE,
			Board::TILE_SIZE,
			1, Colors::Green);
		break;
	case  Type::food:
			gfx.DrawRect(rect.left,
				rect.top,
				Board::TILE_SIZE,
				Board::TILE_SIZE,
			    Colors::Green);
			break;
	}
	
	
	
}

void Board::Tile::SpawnObject(Type object_type)
{
	if (eType == Type::empty)
	{
		eType = object_type;
	}
	
}


RectI Board::Tile::getRect()
{
	return rect;
}

Board::Board(RectI field)
	:
	field(field)
{

	for (int i = 0; i < nTILES_MAX;i++)
	{
		tiles[i] = {RectI(
			field.left + (i % width) *TILE_SIZE,
			field.left + (i % width) * TILE_SIZE + TILE_SIZE,
			field.top + (i / width)* TILE_SIZE,
			field.top + (i / width) * TILE_SIZE + TILE_SIZE) 
		};
		

	}

}

void Board::Draw(Graphics&gfx)

{

	gfx.DrawRectEmpty(field.left, field.top,  (width * TILE_SIZE),(height * TILE_SIZE), 2, Colors::White);
	
	for (int i = 0; i < nTILES_MAX; i++)
	{
		tiles[i].Draw(gfx);
	}
}

Vec2 Board::Board2Screen(const Vec2& pos, Board& brd)
{
	return Vec2(brd.field.left + GetTileSize() * pos.x,
		brd.field.top + GetTileSize() * pos.y
	);
}

 int Board::GetTileSize()
{
	return TILE_SIZE;
}

 int Board::Get_width()
 {
	 return width;
 }

 int Board::Get_height()
 {
	 return height;
 }

 

