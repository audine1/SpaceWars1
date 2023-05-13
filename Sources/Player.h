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
	inline Player();
	inline Player(Texture* texture);
	inline Sprite GetPlayerShape();
	inline int GetHP();
	inline int GetHPMax();
	inline void operator-- ();
	inline void ScoreInc(int x);
	inline int GetScore();
	inline void SetShootTimer(int x);
	inline int GetShootTimer();
	inline void ShootTimerInc();
	inline void move();
	inline void windowCollision(RenderWindow& window);
	inline ~Player();
};