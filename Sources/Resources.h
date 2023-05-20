#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Resources
{
private:
	Font font;
	Texture playerTex, bulletTex;
	Texture enemyTexEasy, enemyTexMedium, enemyTexHard;
	Text scoreText;
	Text gameOverText;
	Text hpText;
	Text eHpText;
	Text escapeMenu;
public:
	Resources();
	~Resources();
	friend class Game;
	Font GetFont();
};