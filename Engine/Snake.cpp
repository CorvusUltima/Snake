#include "Snake.h"

void Snake::Segment::Draw(Graphics& gfx, Board& brd,Color c)
{
	const Vec2 drawpos = Board::Board2Screen(pos,brd);

	gfx.DrawRectDim(drawpos.x,drawpos.y, Board::GetTileSize(),  Board::GetTileSize(),c);
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

Vec2 Snake::Segment::GetPos()
{
	return pos;
}

Vec2 Snake::Segment::SetPos(Vec2 newPos)
{
	pos = newPos;
	return pos;
}


Snake::Segment::Segment(Vec2 pos)
	:
	pos(pos)
{
}



Snake::Snake()
{
	segments[0] = { start_pos };
	
}
	


void Snake::Draw(Graphics& gfx, Board& brd)
{
	
	segments[0].Draw(gfx, brd, Colors::Red);
	
	for (int i = 1; i < nSegments_currant; i++)
	{
		segments[i].Draw(gfx,brd,Colors::Blue);
	}
}


void Snake::Update(Keyboard& kbd, Board& brd)
{
	for (int i = 1; i < nSegments_currant; i++)
	{
		Coliding(segments[0].GetPos(),segments[i].GetPos());
	}
	
		ProcesConsuption(brd);
		if (!bIsDeath)
		{
			timer += dt.Mark() * speed;

			if (kbd.KeyIsPressed(VK_LEFT) || kbd.KeyIsPressed('A') && vel.x != 1)
			{
				vel = { -1,0 };
			}
			if (kbd.KeyIsPressed(VK_RIGHT) || kbd.KeyIsPressed('D') && vel.x != -1)
			{
				vel = { 1,0 };
			}
			if (kbd.KeyIsPressed(VK_UP) || kbd.KeyIsPressed('S') && vel.y != -1)
			{
				vel = { 0,1 };
			}
			if (kbd.KeyIsPressed(VK_DOWN) || kbd.KeyIsPressed('W') && vel.y != 1)
			{
				vel = { 0,-1 };
			}

		}
		if (timer >= 1.0f)
		{
			if(segments[0].GetPos().y+vel.y < 0 || segments[0].GetPos().y+vel.y > Board::Get_height()-1 ||
				segments[0].GetPos().x+vel.x < 0 || segments[0].GetPos().x+vel.x > Board::Get_width()-1
			)
			{
				bIsDeath =true;
			}

			
			
			if (!bIsDeath)
			{
				segments[0].Move(vel, brd);
			}
			



			for (int i = 1; i < nSegments_currant; i++)
			{
				segments[i].Folow(segments[i - 1].GetOldPos());
			}
			timer = 0;
			
		}
	

	






}

void Snake::ProcesConsuption(Board& brd)
{
	
	if (brd.IsFood(brd.tileAt(segments[0].GetPos())))
	{	

	   Grow();
	   brd.restartTile(brd.tileAt(segments[0].GetPos()));

	}
	if (brd.IsPoison(brd.tileAt(segments[0].GetPos())))
	{

		brd.restartTile(brd.tileAt(segments[0].GetPos()));
		speed++;
	}

}


void Snake::Grow()
{	
	segments[nSegments_currant].SetPos(segments[nSegments_currant - 1].GetOldPos());
	++nSegments_currant;
}

void  Snake::Coliding(Vec2 pos, Vec2 pos2)
{
	if (pos.x == pos2.x && pos.y == pos2.y)
	{
		bIsDeath = true;
	}
	
}

bool Snake::GetbIsDead()
{
	return bIsDeath;
}

void Snake::RestartGame(Board& brd)
{
	
	segments[0].SetPos(start_pos);
	int  nSegments_currant = 1;
	int speed =3;
	bool bIsDeath = false;
	brd.RestartBoard();

}



