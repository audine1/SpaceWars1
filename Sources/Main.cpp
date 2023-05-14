#include "Headers.h"

int main()
{
	srand(time(NULL));
	RenderWindow window(VideoMode(800, 600), "Space wars", Style::Default);
	Menu menu(window.getSize().x, window.getSize().y);
	Game game;

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.MoveUp();
					break;

				case Keyboard::Down:
					menu.MoveDown();
					break;

				case Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						game.Run(window);
						break;
					case 1:
						cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		menu.draw(window);

		window.display();
	}

	/*Game game;
	game.Run(window);*/
}