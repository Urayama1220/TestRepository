#include "Player.h"
#include "Enemy.h"

void Player::OnDamage(int damage)
{
	life_ -= damage;
}

void Player::Attack()
{
	enemy_->OnDamage(10);
}
