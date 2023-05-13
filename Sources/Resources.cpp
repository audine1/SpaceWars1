#include "Resources.h"

Resources::Resources()
{
	playerTex.loadFromFile("Resources/spaceship.png");
	enemyTex.loadFromFile("Resources/enemy.png");
	bulletTex.loadFromFile("Resources/missile.png");

	font.loadFromFile("Resources/arialbd.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(10.f, 10.f);

	gameOverText.setFont(font);
	gameOverText.setCharacterSize(30);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setPosition(100.f, 300.f);
	gameOverText.setString("GAME OVER!");

	hpText.setFont(font);
	hpText.setCharacterSize(12);
	hpText.setFillColor(Color::White);

	eHpText.setFont(font);
	eHpText.setCharacterSize(12);
	eHpText.setFillColor(Color::White);
}

Resources::~Resources() {}