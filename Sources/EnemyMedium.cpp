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

EnemyMedium::~EnemyMedium() {}

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

void EnemyMedium::Move(RenderWindow& window)
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

Vector2f EnemyMedium::RandomMovement()
{
	float directionY = (rand() % 2 == 0) ? 1.0f : -1.0f;
	float movementY = 1.5f * directionY;
	return Vector2f(-6.f, movementY);
}
