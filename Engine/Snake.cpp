#include "Snake.h"

void Snake::Segment::Draw(Graphics& gfx, Board& brd)
{
	const Vec2 drawpos = Board::Board2Screen(pos,brd);

	gfx.DrawRectDim(drawpos.x,drawpos.y, Board::GetTileSize(),  Board::GetTileSize(),Colors::Blue);
}

void Snake::Segment::Move(Vec2 vec,Board& brd)
{
	Vec2 temp = pos;
	pos += vec;
	old_pos = temp;
}

void Snake::Segment::Folow(Vec2 old_pos_other)
{
	Vec2 temp = pos;
	pos = old_pos_other;
	old_pos = temp;
}

Vec2 Snake::Segment::GetOldPos()const
{
	return old_pos;
}


Snake::Segment::Segment(Vec2 pos)
	:
	pos(pos)
{

}



Snake::Snake()
{
	segments[0] = { start_pos };
	for (int i = 1; i < nSegments_currant; i++)
	{
		segments[i] = { segments[i - 1].GetOldPos() };
	}
}
	


void Snake::Draw(Graphics& gfx, Board& brd)
{
	for (int i = 0; i < nSegments_currant; i++)
	{
		segments[i].Draw(gfx,brd);
	}
}


void Snake::Update(Keyboard& kbd, Board& brd)
{

	



	timer += dt.Mark();
	
	if (kbd.KeyIsPressed(VK_LEFT)|| kbd.KeyIsPressed('A')&&vel.x!=1)
	{
		vel = { -1,0 };
	}
	if (kbd.KeyIsPressed(VK_RIGHT) || kbd.KeyIsPressed('D') && vel.x !=- 1)
	{
		vel = { 1,0 };
	}
	if (kbd.KeyIsPressed(VK_UP)||kbd.KeyIsPressed('S') && vel.y != -1)
	{
		vel ={ 0,1 };
	}
	if (kbd.KeyIsPressed(VK_DOWN) || kbd.KeyIsPressed('W') && vel.y != 1)
	{
		vel={ 0,-1 };
	}


		if(timer >= 1.0f)
	{
		segments[0].Move(vel, brd);
		for (int i = 1; i < nSegments_currant; i++)
		{
			segments[i].Folow(segments[i-1].GetOldPos());
		}
	
		timer = 0;

	}






   
}

void Snake::Grow()
{
	nSegments_currant++;
}


