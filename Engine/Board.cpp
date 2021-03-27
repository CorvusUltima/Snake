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
				rect.left+Board::TILE_SIZE,
				rect.top+Board::TILE_SIZE,
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

void Board::Tile::SetEmpty(Tile& tile)
{
	tile.eType = Type::empty;
}



RectI Board::Tile::getRect()
{
	return rect;
}

Board::Tile::Type Board::Tile::getType()
{
	return eType;
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
	
	int random = rng::rdm_int(0, nTILES_MAX);
	
	tiles[random].SpawnObject(Tile::Type::food);
	

}

void Board::Draw(Graphics&gfx)
{
	gfx.DrawRectEmpty(field.left, field.top,  (width * TILE_SIZE),(height * TILE_SIZE), 2, Colors::White);
	
	for (int i = 0; i < nTILES_MAX; i++)
	{
		tiles[i].Draw(gfx);
	}
}

bool Board::IsFood(Tile& tile)
{
	return tile.getType()==Tile::Type::food;
}

Board::Tile& Board::tileAt(Vec2& pos)
{	
	return tiles[pos.y * width + pos.x];
}

void Board::restartTile(Tile& tile)
{
	tile.SetEmpty(tile);
	int rand = rng::rdm_int(0, nTILES_MAX);
	tiles[rand].SpawnObject(Tile::Type::food);
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

 

