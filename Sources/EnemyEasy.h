#pragma once
#include <SFML\Graphics.hpp>
#include "Enemy.h"
using namespace sf;

class EnemyEasy : public Enemy
{
private:
	Sprite shape;
	int HP;
	int HPMax;
public:

	inline EnemyEasy(Texture* texture, Vector2u windowSize);
	inline Sprite GetEnemyShape();
	inline int GetHP();
	inline int GetHPMax();
	inline void operator-- ();
	inline void Move();
	inline ~EnemyEasy();
};