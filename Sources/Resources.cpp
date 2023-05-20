#include "Resources.h"

Resources::Resources()
{
	playerTex.loadFromFile("Resources/spaceship.png");
	enemyTexEasy.loadFromFile("Resources/enemy.png");
	enemyTexMedium.loadFromFile("Resources/enemyMedium.png");
	enemyTexHard.loadFromFile("Resources/enemyHard.png");
	bulletTex.loadFromFile("Resources/missile.png");

	font.loadFromFile("Resources/arialbd.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(10.f, 10.f);

	gameOverText.setFont(font);
	gameOverText.setCharacterSize(30);
	gameOverText.setFillColor(Color::Red);
	gameOverText.setPosition(300.f, 100.f);
	gameOverText.setString("GAME OVER!");

	hpText.setFont(font);
	hpText.setCharacterSize(12);
	hpText.setFillColor(Color::White);

	eHpText.setFont(font);
	eHpText.setCharacterSize(12);
	eHpText.setFillColor(Color::White);

	escapeMenu.setFont(font);
	escapeMenu.setCharacterSize(30);
	escapeMenu.setFillColor(Color::White);
	escapeMenu.setPosition(250.f, 200.f);
	escapeMenu.setString("Press Escape to exit");
}

Resources::~Resources() {}

Font Resources::GetFont()
{
	return font;
}