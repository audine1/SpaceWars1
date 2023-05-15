#include "DifficultyMenu.h"

DifficultyMenu::DifficultyMenu() {}

DifficultyMenu::DifficultyMenu(float width, float height)
{
	difficulty = new Text[MAX_NUMBER_OF_ITEMS1];
	font.loadFromFile("Resources/arialbd.ttf");

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

void DifficultyMenu::Run(RenderWindow& Difficulty, int& selectedEnemyType)
{
	while (Difficulty.isOpen())
	{
		Event event;
		while (Difficulty.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				Difficulty.close();
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					MoveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					MoveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					int x = GetPressedItem();
					if (x >= 0 && x <= 2)
					{
						selectedEnemyType = x;
						Difficulty.close();
					}
					if (x == 3)
					{
						Difficulty.close();
					}
				}
			}
		}
		Difficulty.clear();
		draw(Difficulty);
		Difficulty.display();
	}
}

void DifficultyMenu::draw(RenderWindow& Difficulty)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS1; i++)
	{
		Difficulty.draw(difficulty[i]);
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

int DifficultyMenu::GetPressedItem()
{
	return selectedItemIndex;
}
