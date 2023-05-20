#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

using namespace sf;
using namespace std;

const int MAX_NUMBER_OF_ITEMS1 = 4;

class DifficultyMenu
{
private:
	Resources resources;
	int selectedItemIndex;
	Font font;
	Text* difficulty = nullptr;
public:
	DifficultyMenu();
	DifficultyMenu(float width, float height);
	~DifficultyMenu();

	void Run(RenderWindow& Difficulty, int& selectedEnemyType);
	void Draw(RenderWindow& Difficulty);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();
};