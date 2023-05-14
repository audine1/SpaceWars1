#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Resources
{
private:
	Font font;
	Texture playerTex, enemyTex, bulletTex;
	Text scoreText;
	Text gameOverText;
	Text hpText;
	Text eHpText;
public:
	inline Resources();
	friend class Game;
	//inline Font& GetFont();
	inline ~Resources();
};