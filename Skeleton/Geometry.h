#pragma once
struct Vector2 {
	float x;
	float y;

	Vector2()
	{
		Vector2(0, 0);
	}
	Vector2(float inx, float iny) :x(inx),y(iny)
	{

	}

	//ベクトルの大きさを返す
	float Magnitude()const;	
	//ベクトルの大きさの２条を返す
	float SQMagnitude()const;
	//ベクトルの正規化する
	void Normalize();
	//ベクトルを正規化してベクトルを返す
	Vector2 Normalized() const;
	//90ド回転
	void Rotate90();
	Vector2 Rotated90() const;
	static const Vector2 Zero()
	{
		return{ 0.0f,0.0f };
	};
	//代入
	void operator= (const Vector2& rval);
	void operator+= (const Vector2& rval);
	void operator-= (const Vector2& rval);
	void operator*= (const float scale);
	void operator/= (const float div);
	bool operator== (const Vector2& val)const;
};


Vector2 operator+(const Vector2& lval, const Vector2& rval);
Vector2 operator-(const Vector2& lval, const Vector2& rval);
Vector2 operator*(const Vector2& lval, const Vector2& rval);
Vector2 operator*(const Vector2& lval, const float scale);
Vector2 operator/(const Vector2& lval, const float div);

using Position2 = Vector2;
//矩形構造体
struct Rect {
	Position2 center;
	float w, h;
	float Left()const;
	float Top()const;
	float Right()const;
	float Bottom()const;
	float Width()const;
	float Height()const;

};
//円の構造体
struct Circle
{
	Position2 center;
	float radius;
};