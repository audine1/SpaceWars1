#pragma once
#include <SFML\Graphics.hpp>
#include "Enemy.h"
using namespace sf;

class EnemyHard : public Enemy
{
private:
	Sprite shape;
	int HP;
	int HPMax;
public:
	inline EnemyHard();
	EnemyHard(Texture* texture, Vector2u windowSize);
	inline ~EnemyHard() override;
	inline void Shoot() override;
	inline Sprite GetEnemyShape() override;
	inline int GetHP() override;
	inline int GetHPMax() override;
	inline void operator-- () override;
	inline void Move() override;
};