
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
