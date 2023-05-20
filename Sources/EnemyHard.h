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
	float individualTimer;
	Vector2f velocity;
public:
	EnemyHard();
	EnemyHard(Texture* texture, Vector2u windowSize);
	~EnemyHard() override;
	void Shoot() override;
	Sprite GetEnemyShape() override;
	int GetHP() override;
	int GetHPMax() override;
	void operator-- () override;
	void Move(RenderWindow& window) override;
	Vector2f RandomMovement() override;
};