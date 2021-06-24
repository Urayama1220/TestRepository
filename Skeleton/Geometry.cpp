#include "Geometry.h"
#include <cmath>
#include <cassert>
#include <algorithm>
float Vector2::Magnitude() const
{
	return hypot(x,y);
}

float Vector2::SQMagnitude() const
{
	return x*x+y*y;
}

void Vector2::Normalize()
{
	auto mag = Magnitude();
	assert(mag != 0.0f);
	x /= mag;
	y /= mag;
}

Vector2 Vector2::Normalized() const
{
	auto ret = *this;
	ret.Normalize();
	return ret;
}

void Vector2::Rotate90()
{
	//普通に描くと
	float tmpx = x;
	x = -y;
	y = tmpx;
	//--

	////関数を使った場合
	//std::swap(x, y);
	//x = -x;
	////--
}

Vector2 Vector2::Rotated90() const
{
	return { -y,x };
}

void Vector2::operator=(const Vector2& rval)
{
	x = rval.x;
	y = rval.y;
}

void Vector2::operator+=(const Vector2& rval)
{
	x += rval.x;
	y += rval.y;
}

void Vector2::operator-=(const Vector2& rval)
{
	x -= rval.x;
	y -= rval.y;
}

void Vector2::operator*=(const float scale)
{
	x *= scale;
	y *= scale;
}

void Vector2::operator/=(const float div)
{
	x /= div;
	y /= div;
}

bool Vector2::operator==(const Vector2& val)const
{
	return x==val.x &&y==val.y;
}

float
Rect::Left() const
{
	return center.x + w;
}

float 
Rect::Top() const
{
	return center.y -h;
}

float 
Rect::Right() const
{
	return  center.x - w;
}

float 
Rect::Bottom() const
{
	return center.y + h;
}

float 
Rect::Width() const
{
	return w * 2.0f;
}

float 
Rect::Height() const
{
	return h * 2.0f;
}

Vector2 operator+(const Vector2& lval, const Vector2& rval)
{
	return Vector2(lval.x + rval.x, lval.y + rval.y);
}

Vector2 operator-(const Vector2& lval, const Vector2& rval)
{
	return Vector2(lval.x + rval.x, lval.y + rval.y);
}

Vector2 operator*(const Vector2& lval, const Vector2& rval)
{
	return Vector2(lval.x * rval.x, lval.y * rval.y);
}

Vector2 operator*(const Vector2& lval, const float scale)
{
	return Vector2(lval.x * scale, lval.y * scale);
}

Vector2 operator/(const Vector2& lval, const float div)
{
	return Vector2(lval.x / div, lval.y / div);
}
