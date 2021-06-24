#pragma once
class Player;//プロトタイプ宣言
class Enemy
{
	Player* player_;
	int life_ = 100;
public:
	void OnDamage(int damage);
	void Attack();
};

