#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
const int MaxMainMenu = 3;

class MainMenu
{
private:
	int mainMenuSelected;
	Font font;
	Text *mainMenu;
public:
	inline MainMenu();
	inline void Draw(RenderWindow& window);
	inline void MoveUp();
	inline void MoveDown();
	inline int MainMenuPressed();
	inline ~MainMenu();
};