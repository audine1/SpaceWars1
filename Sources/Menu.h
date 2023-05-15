#pragma once
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "DifficultyMenu.h"

using namespace sf;
const int MAX_NUMBER_OF_ITEMS = 3;

class Menu
{
private:
	DifficultyMenu difficultyMenu = DifficultyMenu(800, 600);
	Game game;
	int selectedItemIndex;
	Font font;
	Text* menu = nullptr;
public:
	inline Menu();
	inline Menu(float width, float height);
	inline void Run(RenderWindow& window);
	inline ~Menu();
private:
	inline void draw(RenderWindow& window);
	inline void MoveUp();
	inline void MoveDown();
	inline int GetPressedItem();
};