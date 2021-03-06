#pragma once
class Vec2
{
public:
	Vec2() = default;
	Vec2(int in_x, int in_y);
	Vec2 operator+ (const Vec2& rhs) const;
	Vec2& operator+= (const Vec2& rhs);
	bool operator== (Vec2& rhs)const;
	Vec2 operator* (float rhs) const;
	Vec2& operator*= (float rhs);
	Vec2 operator- (const Vec2& rhs) const;
	Vec2& operator-= (const Vec2& rhs);
	float GetLength() const;
	float GetLengthSq() const;
	Vec2& Normalize();
	Vec2 GetNormalized() const;

	int x;
	int y;
};

