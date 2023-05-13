#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Enemy
{
private:
	Sprite shape;
	int HP;
	int HPMax;
public:

	inline Enemy(Texture* texture, Vector2u windowSize);
	inline Sprite GetEnemyShape();
	inline int GetHP();
	inline int GetHPMax();
	inline void operator-- ();
	inline void Move();
	inline ~Enemy();
};