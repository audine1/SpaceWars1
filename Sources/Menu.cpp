#include "Menu.h"

using namespace sf;

Menu::Menu() {}

Menu::Menu(float width, float height)
{
	menu = new Text[MAX_NUMBER_OF_ITEMS];
	font.loadFromFile("Resources/arialbd.ttf");

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Menu::~Menu() { delete[] menu; }

void Menu::Run(RenderWindow& window)
{
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
					MoveUp();
					break;

				case Keyboard::Down:
					MoveDown();
					break;

				case Keyboard::Return:
					switch (GetPressedItem())
					{
					case 0:
						game.Run(window);
						break;
					case 1:
						difficultyMenu.Run(window);
						break;
					case 2:
						window.close();
						break;
					}
					break;
				}

				break;
			case Event::Closed:
				window.close();

				break;
			}
		}

		window.clear();
		draw(window);
		window.display();
	}
}

void Menu::draw(RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}