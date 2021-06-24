#pragma once
class Enemey;

class Player
{
	Enemey* enemy_;//
	int life_ = 100;
public:
	void OnDamage(int damage);
	void Attack();
};

