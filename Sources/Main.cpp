#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <cmath>
#include <cstdlib>
#include <vector>
#include "Bullet.h"
#include "Player.h"
#include "EnemyEasy.h"
#include "Resources.h"
#include "Game.h"
#include "Menu.h"
#include "DifficultyMenu.h"

int main()
{
	srand(time(NULL)); 
	RenderWindow window(VideoMode(800, 600), "Space wars", Style::Default);
	window.setFramerateLimit(60);
	Menu menu(window.getSize().x, window.getSize().y);
	menu.Run(window);
}