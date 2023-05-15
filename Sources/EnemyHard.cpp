#include "EnemyHard.h"

EnemyHard::EnemyHard() {}

EnemyHard::EnemyHard(Texture* texture, Vector2u windowSize)
{
	HPMax = rand() % 10 + 1;
	HP = HPMax;

	shape.setTexture(*texture);
	shape.setScale(0.15f, 0.15f);
	shape.setPosition(windowSize.x - shape.getGlobalBounds().width, rand() % (int)(windowSize.y - shape.getGlobalBounds().height));
}

EnemyHard::~EnemyHard() {}

inline void EnemyHard::Move()
{
	shape.move(-7.f, 0.f);
}

void EnemyHard::Shoot() {}

Sprite EnemyHard::GetEnemyShape()
{
	return shape;
}

int EnemyHard::GetHP()
{
	return HP;
}

int EnemyHard::GetHPMax()
{
	return HPMax;
}

void EnemyHard::operator--()
{
	HP--;
}
