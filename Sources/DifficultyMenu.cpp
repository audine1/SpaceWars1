#include "DifficultyMenu.h"

DifficultyMenu::DifficultyMenu() {}

DifficultyMenu::DifficultyMenu(float width, float height)
{
	difficulty = new Text[MAX_NUMBER_OF_ITEMS1];

	difficulty[0].setFont(font);
	difficulty[0].setFillColor(Color::White);
	difficulty[0].setString("Easy");
	difficulty[0].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS1 + 1) * 1));

	difficulty[1].setFont(font);
	difficulty[1].setFillColor(Color::White);
	difficulty[1].setString("Medium");
	difficulty[1].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS1 + 1) * 2));

	difficulty[2].setFont(font);
	difficulty[2].setFillColor(Color::White);
	difficulty[2].setString("Hard");
	difficulty[2].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS1 + 1) * 3));

	difficulty[3].setFont(font);
	difficulty[3].setFillColor(Color::White);
	difficulty[3].setString("Exit");
	difficulty[3].setPosition(Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS1 + 1) * 4));

	selectedItemIndex = 0;
}

DifficultyMenu::~DifficultyMenu() { delete[] difficulty; }

void DifficultyMenu::Run(RenderWindow& window)
{
	window.clear();
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
						//setDifficultyEasy
						break;
					case 1:
						//cout << "Option button has been pressed" << endl;
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

void DifficultyMenu::draw(RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS1; i++)
	{
		window.draw(difficulty[i]);
	}
}

void DifficultyMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		difficulty[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		difficulty[selectedItemIndex].setFillColor(Color::Red);
	}
}

void DifficultyMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS1)
	{
		difficulty[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		difficulty[selectedItemIndex].setFillColor(Color::Red);
	}
}