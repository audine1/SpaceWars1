#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Enemy
{
public:
	virtual Sprite GetEnemyShape() = 0;
	virtual void Shoot() = 0;
	virtual int GetHP() = 0;
	virtual int GetHPMax() = 0;
	virtual void operator--() = 0;
	virtual void Move() = 0;
	virtual ~Enemy() {}
};