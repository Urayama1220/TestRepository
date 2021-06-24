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

	//�x�N�g���̑傫����Ԃ�
	float Magnitude()const;	
	//�x�N�g���̑傫���̂Q����Ԃ�
	float SQMagnitude()const;
	//�x�N�g���̐��K������
	void Normalize();
	//�x�N�g���𐳋K�����ăx�N�g����Ԃ�
	Vector2 Normalized() const;
	//90�h��]
	void Rotate90();
	Vector2 Rotated90() const;
	static const Vector2 Zero()
	{
		return{ 0.0f,0.0f };
	};
	//���
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
//��`�\����
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
//�~�̍\����
struct Circle
{
	Position2 center;
	float radius;
};