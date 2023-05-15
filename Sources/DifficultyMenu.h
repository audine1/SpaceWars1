#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "EnemyEasy.h"

using namespace sf;
const int MAX_NUMBER_OF_ITEMS1 = 4;

class DifficultyMenu
{
private:
	int selectedItemIndex;
	Font font;
	Text* difficulty = nullptr;
public:
	inline DifficultyMenu();
	inline DifficultyMenu(float width, float height);
	inline ~DifficultyMenu();

	inline void Run(RenderWindow& Difficulty, int& selectedEnemyType);
	inline void draw(RenderWindow& Difficulty);
	inline void MoveUp();
	inline void MoveDown();
	inline int GetPressedItem() { return selectedItemIndex; }
};