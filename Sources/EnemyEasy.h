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
	inline EnemyEasy();
	inline EnemyEasy(Texture* texture, Vector2u windowSize);
	inline void Spawn(Texture* texture, Vector2u windowSize) override;
	inline void Shoot() override;
	inline Sprite GetEnemyShape() override;
	inline int GetHP() override;
	inline int GetHPMax() override;
	inline void operator-- () override;
	inline void Move() override;
	inline ~EnemyEasy() override;
};