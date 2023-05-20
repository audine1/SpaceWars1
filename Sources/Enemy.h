#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

//abstract class
class Enemy
{
public:
	virtual Sprite GetEnemyShape() = 0;
	virtual void Shoot() = 0;
	virtual int GetHP() = 0;
	virtual int GetHPMax() = 0;
	virtual void operator--() = 0;
	virtual void Move(RenderWindow& window) = 0;
	virtual Vector2f RandomMovement() = 0;
	virtual ~Enemy() {}
};