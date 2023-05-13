#include "Headers.h"

int main()
{
	srand(time(NULL));
	RenderWindow window(VideoMode(800, 600), "Space wars", Style::Default);
	window.setFramerateLimit(60);
	Game game;
	game.Run(window);
}