#pragma once
class Player;//�v���g�^�C�v�錾
class Enemy
{
	Player* player_;
	int life_ = 100;
public:
	void OnDamage(int damage);
	void Attack();
};

