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
			1, Colors::Black);
		
		break;

	case  Type::food:
			gfx.DrawRect(rect.left,
				rect.top,
				rect.left+Board::TILE_SIZE,
				rect.top+Board::TILE_SIZE,
			    Colors::Green);
			break;

	case  Type::poison:
		gfx.DrawRect(rect.left,
			rect.top,
			rect.left + Board::TILE_SIZE,
			rect.top + Board::TILE_SIZE,
			Colors::Magenta);

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


Board::Board(RectI field, int width, int height, int nPoison)
	:
	width(width),
	height(height),
	field(field),
	tiles(new Tile[width*height]),
	nPoison(nPoison)
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
	for (int i = 0; i < nPoison; i++)
	{
		int random = rng::rdm_int(0, nTILES_MAX);
		
		if (tiles[random].getType() == Tile::Type::empty) tiles[random].SpawnObject(Tile::Type::poison);
		else i--;

	}
	

}

Board::~Board()
{
	delete[] tiles;
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

bool Board::IsPoison(Tile& tile)
{
	return  tile.getType() == Tile::Type::poison;
}

Board::Tile& Board::tileAt(Vec2& pos)
{	
	return tiles[pos.y * width + pos.x];
}

void Board::restartTile(Tile& tile)
{
	if (tile.getType() == Tile::Type::food)
	{
		tile.SetEmpty(tile);
		int rand = rng::rdm_int(0, nTILES_MAX);
		tiles[rand].SpawnObject(Tile::Type::food);
	}

	else if (tile.getType() == Tile::Type::poison)
	{
		tile.SetEmpty(tile);
	}
	
}

void Board::RestartBoard()
{
	for (int i = 0; i < nPoison; i++)
	{
		int random = rng::rdm_int(0, nTILES_MAX);

		if (tiles[random].getType() == Tile::Type::empty) tiles[random].SpawnObject(Tile::Type::poison);
		else i--;

	}
}


Vec2 Board::Board2Screen(const Vec2& pos, Board& brd)
{
	return Vec2(brd.field.left + GetTileSize() * pos.x,
		brd.field.top + GetTileSize() * pos.y
	);
}

Vec2 Board::Board2Screen(const Vec2& pos, Board* pBrd)
{
	return Vec2(pBrd->field.left + GetTileSize() * pos.x,
		pBrd->field.top + GetTileSize() * pos.y
	);
}

constexpr int Board::GetTileSize()
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

 RectI Board::GetField()const
 {
	 return field;
 }

 

