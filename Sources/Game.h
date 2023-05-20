#pragma once
#include <SFML\Graphics.hpp>
#include "Resources.h"
#include "Player.h"
#include "EnemyEasy.h"
#include "EnemyMedium.h"
#include "EnemyHard.h"
#include "Enemy.h"
#include "Bullet.h"

using namespace std;
using namespace sf;

class Game
{
private:
	Resources resources;
	Event event;
	Player player;
	vector<Enemy*> enemies;
	vector<Bullet> bullets;
	int enemySpawnTimer = 0;
public:
	Game();
	~Game();
	void Run(RenderWindow& window, int& selectedEnemyType);
private:
	void Menu(RenderWindow& window);
	void PlayerFunc(RenderWindow& window);
	void Shoot();
	void EnemyCollision(int i);
	void Bullets(RenderWindow& window);
	void EnemySpawner(RenderWindow& window, int&selectedEnemyType);
	void Enemys(RenderWindow& window);
	void Draw(RenderWindow& window);
};