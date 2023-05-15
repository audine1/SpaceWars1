#include "EnemyEasy.h"

inline EnemyEasy::EnemyEasy() {}

EnemyEasy::EnemyEasy(Texture* texture, Vector2u windowSize)
{
	HPMax = rand() % 3 + 1;
	HP = HPMax;

	shape.setTexture(*texture);
	shape.setScale(0.15f, 0.15f);
	shape.setPosition(windowSize.x - shape.getGlobalBounds().width, rand() % (int)(windowSize.y - shape.getGlobalBounds().height));
}

void EnemyEasy::Spawn(Texture* texture, Vector2u windowSize)
{
	HPMax = rand() % 3 + 1;
	HP = HPMax;

	shape.setTexture(*texture);
	shape.setScale(0.15f, 0.15f);
	shape.setPosition(windowSize.x - shape.getGlobalBounds().width, rand() % (int)(windowSize.y - shape.getGlobalBounds().height));
}

void EnemyEasy::Shoot() {}

Sprite EnemyEasy::GetEnemyShape()
{
	return shape;
}

int EnemyEasy::GetHP()
{
	return HP;
}

int EnemyEasy::GetHPMax()
{
	return HPMax;
}

void EnemyEasy::operator--()
{
	HP--;
}

void EnemyEasy::Move()
{
	shape.move(-1.f, 0.f);
}

EnemyEasy::~EnemyEasy() {}