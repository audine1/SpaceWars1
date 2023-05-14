#pragma once
#include <SFML/Graphics.hpp>

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

	inline void Run(RenderWindow& window);
	inline void draw(RenderWindow& window);
	inline void MoveUp();
	inline void MoveDown();
	inline int GetPressedItem() { return selectedItemIndex; }
};