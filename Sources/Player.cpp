#include "Player.h"

Player::Player() {}

Player::Player(Texture* texture)
{
	HPMax = 10;
	HP = HPMax;

	this->texture = texture;
	shape.setTexture(*texture);
	shape.setScale(0.15f, 0.15f);
}

Player::~Player() {}

Sprite Player::GetPlayerShape()
{
	return shape;
}

int Player::GetHP()
{
	return HP;
}

int Player::GetHPMax()
{
	return HPMax;
}

void Player::operator--()
{
	HP--;
}

void Player::ScoreInc(int x)
{
	score += x;
}

int Player::GetScore()
{
	return score;
}

void Player::SetShootTimer(int x)
{
	shootTimer = x;
}

int Player::GetShootTimer()
{
	return shootTimer;
}

void Player::ShootTimerInc()
{
	shootTimer++;
}

void Player::move()
{
	if (Keyboard::isKeyPressed(Keyboard::W))
		shape.move(0.f, -10.f);
	if (Keyboard::isKeyPressed(Keyboard::A))
		shape.move(-10.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::S))
		shape.move(0.f, 10.f);
	if (Keyboard::isKeyPressed(Keyboard::D))
		shape.move(10.f, 0.f);
}

void Player::windowCollision(RenderWindow& window)
{
	if (shape.getPosition().x <= 0) //Left
		shape.setPosition(0.f, shape.getPosition().y);
	if (shape.getPosition().x >= window.getSize().x - shape.getGlobalBounds().width) //Right
		shape.setPosition(window.getSize().x - shape.getGlobalBounds().width, shape.getPosition().y);
	if (shape.getPosition().y <= 0) //Top
		shape.setPosition(shape.getPosition().x, 0.f);
	if (shape.getPosition().y >= window.getSize().y - shape.getGlobalBounds().height) //Bottom
		shape.setPosition(shape.getPosition().x, window.getSize().y - shape.getGlobalBounds().height);
}