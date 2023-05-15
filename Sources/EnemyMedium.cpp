#include "EnemyMedium.h"

EnemyMedium::EnemyMedium() {}

EnemyMedium::EnemyMedium(Texture* texture, Vector2u windowSize)
{
	HPMax = rand() % 7 + 1;
	HP = HPMax;

	shape.setTexture(*texture);
	shape.setScale(0.15f, 0.15f);
	shape.setPosition(windowSize.x - shape.getGlobalBounds().width, rand() % (int)(windowSize.y - shape.getGlobalBounds().height));
}

void EnemyMedium::Shoot() {}

Sprite EnemyMedium::GetEnemyShape()
{
	return shape;
}

int EnemyMedium::GetHP()
{
	return HP;
}

int EnemyMedium::GetHPMax()
{
	return HPMax;
}

void EnemyMedium::operator--()
{
	HP--;
}

void EnemyMedium::Move()
{
	shape.move(-6.f, 0.f);
}

EnemyMedium::~EnemyMedium() {}
