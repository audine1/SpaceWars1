#include "Bullet.h"

Bullet::Bullet(Texture* texture, Vector2f pos)
{
	shape.setTexture(*texture);
	shape.setScale(0.1f, 0.1f);
	shape.setPosition(pos);
}

Sprite Bullet::GetShape()
{
	return shape;
}

void Bullet::Move()
{
	shape.move(20.f, 0.f);
}

Bullet::~Bullet() {}