
#include "RectI.h"


RectI::RectI(int left, int right, int top, int bottom)
	:
	left(left),
	right(right),
	top(top),
	bottom(bottom)

{

}

RectI::RectI(Vec2 topleft, int width, int height)
	:
	RectI(topleft.x, topleft.x + width, topleft.y, topleft.y + height)
{
	 
}

bool RectI::isOverLappingWith(const RectI& other) const
{
	
	
	return right > other.left && left<other.right&& bottom>other.top && top < other.bottom;
	

	
}

bool RectI::isContaining(const Vec2& point) const
{
	 return point.x > left && point.x < right&& point.y > top && point.y < bottom;
}
