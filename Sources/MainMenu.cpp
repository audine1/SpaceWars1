#include "MainMenu.h"

MainMenu::MainMenu()
{
	mainMenu = new Text[MaxMainMenu];
	font.loadFromFile("Resources/arialbd.ttf");

	//Play
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(400, 200);
	//Options
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Dificulty");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(400, 200);
	//Exit
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(400, 400);

	mainMenuSelected = -1;
}

void MainMenu::Draw(RenderWindow& window)
{
	for (int i = 0; i < MaxMainMenu; i++)
	{
		window.draw(mainMenu[i]);
	}
}

void MainMenu::MoveUp()
{
	if (mainMenuSelected - 1 >= 0)
	{
		mainMenu[mainMenuSelected].setFillColor(Color::White);
	}
	mainMenuSelected--;
	if (mainMenuSelected == -1)
	{
		mainMenuSelected = 2;
	}
	mainMenu[mainMenuSelected].setFillColor(Color::Blue);
}

void MainMenu::MoveDown()
{
	if (mainMenuSelected - 1 <= MaxMainMenu)
	{
		mainMenu[mainMenuSelected].setFillColor(Color::White);
		mainMenuSelected--;
		if (mainMenuSelected == 4)
		{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setFillColor(Color::Blue);
	}
}