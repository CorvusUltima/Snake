#pragma once
#include"Vec2.h"
class RectI
{
public:

	RectI() = default;
	RectI(int left, int right, int top, int bottom);
	RectI(Vec2 topleft,int  width, int height);




	int left;
	int right;
	int top; 
	int bottom;





};

