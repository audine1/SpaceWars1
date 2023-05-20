#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "DifficultyMenu.h"
#include "Resources.h"

using namespace sf;
const int MAX_NUMBER_OF_ITEMS = 3;

class Menu
{
private:
	Resources resources;
	DifficultyMenu difficultyMenu = DifficultyMenu(800, 600);
	Game game;
	int selectedItemIndex;
	Font font;
	Text* menu = nullptr;
public:
	Menu();
	Menu(float width, float height);
	~Menu();
	void Run(RenderWindow& window);
private:
	void Draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();
};