#pragma once
#include <SFML\Graphics.hpp>
#include "Resources.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

using namespace std;
using namespace sf;

class Game
{
private:
	Resources resources;
	MainMenu mainMenu;
	Event event;
	Player player;
	vector<Enemy> enemies;
	vector<Bullet> bullets;
	int enemySpawnTimer = 0;
public:
	inline Game();
	inline void Run(RenderWindow& window);
	inline ~Game();
private:
	inline void Menu(RenderWindow& window);
	inline void PlayerFunc(RenderWindow& window);
	inline void Shoot();
	inline void EnemyCollision(int i);
	inline void Bullets(RenderWindow& window);
	inline void EnemySpawner(RenderWindow& window);
	inline void Enemys();
	inline void Draw(RenderWindow& window);
};