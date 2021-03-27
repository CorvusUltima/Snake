#pragma once
#include"Board.h"
#include"Keyboard.h"
#include"FrameTimer.h"

class Snake
{
private:

	class Segment
	{
		
	public:

		Segment() = default;
		Segment(Vec2 pos);
		void Draw(Graphics& gfx, Board& brd ,Color c );
		void Move(Vec2 vec, Board& brd);
		void Folow(Vec2 old_pos_other);
		Vec2 GetOldPos() const;
		Vec2 GetPos();
		Vec2 SetPos(Vec2 newPos);

	private:
		Vec2 pos;
		Vec2 old_pos=pos;
	};

public:

	Snake();
	
	void Draw(Graphics& gfx,Board& brd);
	void Update(Keyboard& kbd, Board& brd );
	void ProcesConsuption(Board& brd);
	void Grow();	
	void Coliding(Vec2 pos ,Vec2 pos2);
	bool GetbIsDead();
	void RestartGame(Board& brd);

private:

   FrameTimer dt;
   Vec2 vel{ 1,0 };
   float timer = 0;
   Vec2 start_pos = {int(Board::Get_width()/2),int(Board::Get_height()/2)};
   const static int nSEGMENT_MAX=100;
   int  nSegments_currant = 1;
   int speed =2;
   Segment segments[nSEGMENT_MAX];
   bool bIsDeath = false;

};

