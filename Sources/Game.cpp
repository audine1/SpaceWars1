#include "Game.h"
#include "MainMenu.h"

Game::Game() {}

void Game::Run(RenderWindow& window)
{
	player = Player(&resources.playerTex);
	while (window.isOpen())
	{
		Menu(window);
		if (player.GetHP() > 0)
		{
			PlayerFunc(window);
			Shoot();
			Bullets(window);
			EnemySpawner(window);
			Enemys();
			//UI Update
			resources.scoreText.setString("Score: " + to_string(player.GetScore()));
		}
		Draw(window);
	}
}

Game::~Game() {}

void Game::Menu(RenderWindow& window)
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
		}
	}
}

void Game::PlayerFunc(RenderWindow& window)
{
	player.move();
	player.windowCollision(window); //Collision with window
	resources.hpText.setPosition(player.GetPlayerShape().getPosition().x, player.GetPlayerShape().getPosition().y - resources.hpText.getGlobalBounds().height);
	resources.hpText.setString(to_string(player.GetHP()) + "/" + to_string(player.GetHPMax()));
}

void Game::Shoot()
{
	if (player.GetShootTimer() < 15)
	{
		player.ShootTimerInc();
	}

	if (Mouse::isButtonPressed(Mouse::Left) && player.GetShootTimer() >= 15) //Shooting
	{
		bullets.push_back(Bullet(&resources.bulletTex, player.GetPlayerShape().getPosition()));
		player.SetShootTimer(0); //reset timer
	}
}

void Game::EnemyCollision(int i)
{
	for (int k = 0; k < enemies.size(); k++)
	{
		if (bullets[i].GetShape().getGlobalBounds().intersects(enemies[k].GetEnemyShape().getGlobalBounds()))
		{
			if (enemies[k].GetHP() <= 1)
			{
				player.ScoreInc(enemies[k].GetHPMax());
				enemies.erase(enemies.begin() + k);
			}
			else
				--enemies[k]; //ENEMY TAKE DAMAGE

			bullets.erase(bullets.begin() + i);
			break;
		}
	}
}

void Game::Bullets(RenderWindow& window)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		//Move
		bullets[i].Move();
		//bullet out of bounds
		if (bullets[i].GetShape().getPosition().x > window.getSize().x)
		{
			bullets.erase(bullets.begin() + i);
			break;
		}
		EnemyCollision(i);
	}
}

void Game::EnemySpawner(RenderWindow& window)
{
	//Enemy
	if (enemySpawnTimer < 25)
		enemySpawnTimer++;

	//enemy spawn
	if (enemySpawnTimer >= 25)
	{
		enemies.push_back(Enemy(&resources.enemyTex, window.getSize()));
		enemySpawnTimer = 0; //reset timer
	}
}

void Game::Enemys()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].Move();

		if (enemies[i].GetEnemyShape().getPosition().x <= 0 - enemies[i].GetEnemyShape().getGlobalBounds().width)
		{
			enemies.erase(enemies.begin() + i);
			break;
		}

		if (enemies[i].GetEnemyShape().getGlobalBounds().intersects(player.GetPlayerShape().getGlobalBounds()))
		{
			enemies.erase(enemies.begin() + i);

			--player; // PLAYER TAKE DAMAGE
			break;
		}
	}
}

void Game::Draw(RenderWindow& window)
{
	window.clear();

	//player
	window.draw(player.GetPlayerShape());

	//Bullets
	for (int i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i].GetShape());
	}

	//enemy
	for (int i = 0; i < enemies.size(); i++)
	{
		resources.eHpText.setString(to_string(enemies[i].GetHP()) + "/" + to_string(enemies[i].GetHPMax()));
		resources.eHpText.setPosition(enemies[i].GetEnemyShape().getPosition().x, enemies[i].GetEnemyShape().getPosition().y - resources.eHpText.getGlobalBounds().height + 15);
		window.draw(resources.eHpText);
		window.draw(enemies[i].GetEnemyShape());
	}

	//UI
	window.draw(resources.scoreText);
	window.draw(resources.hpText);

	if (player.GetHP() <= 0)
		window.draw(resources.gameOverText);

	window.display();
}