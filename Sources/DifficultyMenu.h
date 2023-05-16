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
	inline DifficultyMenu();
	inline DifficultyMenu(float width, float height);
	inline ~DifficultyMenu();

	inline void Run(RenderWindow& Difficulty, int& selectedEnemyType);
	inline void Draw(RenderWindow& Difficulty);
	inline void MoveUp();
	inline void MoveDown();
	inline int GetPressedItem();
};