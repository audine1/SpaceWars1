#include "Headers.h"
//все работает, только нужно определить все функции MainMenu в .cpp
int main()
{
	srand(time(NULL));
	RenderWindow window(VideoMode(800, 600), "Space wars", Style::Default);
	MainMenu mainMenu(window.getSize().x, window.getSize().y);
	window.setFramerateLimit(60);
	Game game;
	game.Run(window);
}