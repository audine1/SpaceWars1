#include "EnemyEasy.h"

EnemyEasy::EnemyEasy() {}

EnemyEasy::EnemyEasy(Texture* texture, Vector2u windowSize)
{
	HPMax = rand() % 3 + 1;
	HP = HPMax;
	individualTimer = -1;

	shape.setTexture(*texture);
	shape.setScale(0.15f, 0.15f);
	shape.setPosition(windowSize.x - shape.getGlobalBounds().width, rand() % (int)(windowSize.y - shape.getGlobalBounds().height));
}

EnemyEasy::~EnemyEasy() {}

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

void EnemyEasy::Move(RenderWindow &window)
{
	if (individualTimer <= 0.0f)
	{
		Vector2f direction = RandomMovement();
		velocity = direction;
		individualTimer = rand() % 2 + 1;
	}

	shape.move(velocity);

	individualTimer -= 0.02f;

	if (shape.getPosition().y <= 0)
	{
		velocity.y = 1;
	}
	if (shape.getPosition().y >= window.getSize().y - shape.getGlobalBounds().height)
	{
		velocity.y = -1;
	}
}
Vector2f EnemyEasy::RandomMovement()
{
	float directionY = (rand() % 2 == 0) ? 1.0f : -1.0f;
	float movementY = 1.0f * directionY;
	return Vector2f(-6.f, movementY);
}