#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Player
{
private:
	Sprite shape;
	Texture* texture;
	int HP;
	int HPMax;
	int score = 0, shootTimer = 20;
public:
	Player();
	Player(Texture* texture);
	~Player();
	Sprite GetPlayerShape();
	int GetHP();
	int GetHPMax();
	void operator-- ();
	void ScoreInc(int x);
	int GetScore();
	void SetShootTimer(int x);
	int GetShootTimer();
	void ShootTimerInc();
	void move();
	void windowCollision(RenderWindow& window);
};