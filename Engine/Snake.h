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
		void Draw(Graphics& gfx, Board* pBrd ,Color c );
		void Move(Vec2 vec, Board* pBrd);
		void Folow(Vec2 old_pos_other);
		Vec2 GetOldPos() const;
		Vec2 GetPos();
		Vec2 SetPos(Vec2 newPos);

	private:
		Vec2 pos;
		Vec2 old_pos=pos;
	};

public:

	
	Snake(Board* pBrd, int nSegments_currant);
	
	void Draw(Graphics& gfx, Board* pBrd);
	void Update(Keyboard& kbd, Board* pBrd );
	void ProcesConsuption(Board* pBrd);
	void Grow();	
	void Coliding(Vec2 pos ,Vec2 pos2);
	bool GetbIsDead();
	void RestartGame(Board& brd);

private:

   FrameTimer dt;
   Board* pBrd =nullptr;
   Vec2 vel{ 1,0 };
   float timer = 0;
   Vec2 start_pos = {int(pBrd->Get_width()/2),int(pBrd->Get_height()/2)};
   int nSegment_max=100;
   int  nSegments_currant = 1;
   int speed =2;

   Segment* segments=nullptr;
   bool bIsDeath = false;

};

