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
		void Draw(Graphics& gfx, Board& brd);
		void Move(Vec2 vec, Board& brd);
		void Folow(Vec2 old_pos_other);
		Vec2 GetOldPos() const;



	private:
		Vec2 pos;
		Vec2 old_pos=pos;
	};



public:

	
	Snake();
	
	
	void Draw(Graphics& gfx,Board& brd);
	void Update(Keyboard& kbd, Board& brd );
	void Grow();
	


	


private:

   FrameTimer dt;
   Vec2 vel{ 1,0 };
   float timer = 0;
   Vec2 start_pos = {int(Board::Get_width()/2),int(Board::Get_height()/2)};
   const static int nSEGMENT_MAX=100;
   int  nSegments_currant = 15;
   Segment segments[nSEGMENT_MAX];




};

