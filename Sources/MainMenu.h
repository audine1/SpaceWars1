#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
const int MAX_NUMBER_OF_ITEMS = 3;

class Menu
{
private:
	int selectedItemIndex;
	Font font;
	Text *menu = nullptr;
public:
	inline Menu(float width, float height);
	inline ~Menu();

	inline void draw(RenderWindow& window);
	inline void MoveUp();
	inline void MoveDown();
	inline int GetPressedItem() { return selectedItemIndex; }

};