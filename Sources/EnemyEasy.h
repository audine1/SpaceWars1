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
	float individualTimer;
	Vector2f velocity;
public:
	EnemyEasy();
	EnemyEasy(Texture* texture, Vector2u windowSize);
	~EnemyEasy() override;
	void Shoot() override;
	Sprite GetEnemyShape() override;
	int GetHP() override;
	int GetHPMax() override;
	void operator-- () override;
	void Move(RenderWindow& window) override;
	Vector2f RandomMovement();
	Vector2f RandomIndividualTimer();
};