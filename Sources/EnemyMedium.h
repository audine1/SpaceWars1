#pragma once
#include <SFML\Graphics.hpp>
#include "Enemy.h"
using namespace sf;

class EnemyMedium : public Enemy
{
private:
	Sprite shape;
	int HP;
	int HPMax;
	int shootTimer = 0;
	float individualTimer;
	Vector2f velocity;
public:
	EnemyMedium();
	EnemyMedium(Texture* texture, Vector2u windowSize);
	~EnemyMedium() override;
	void Shoot() override;
	Sprite GetEnemyShape() override;
	int GetHP() override;
	int GetHPMax() override;
	void operator-- () override;
	void Move(RenderWindow& window) override;
	Vector2f RandomMovement() override;
};