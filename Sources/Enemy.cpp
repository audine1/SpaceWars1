#include "Enemy.h"

Enemy::Enemy(Texture* texture, Vector2u windowSize)
{
	HPMax = rand() % 3 + 1;
	HP = HPMax;

	shape.setTexture(*texture);
	shape.setScale(0.15f, 0.15f);
	shape.setPosition(windowSize.x - shape.getGlobalBounds().width, rand() % (int)(windowSize.y - shape.getGlobalBounds().height));
}

Sprite Enemy::GetEnemyShape()
{
	return shape;
}

int Enemy::GetHP()
{
	return HP;
}

int Enemy::GetHPMax()
{
	return HPMax;
}

void Enemy::operator--()
{
	HP--;
}

void Enemy::Move()
{
	shape.move(-6.f, 0.f);
}

Enemy::~Enemy() {}
