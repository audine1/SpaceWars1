#include "Game.h"

Game::Game() {}

Game::~Game()
{
	for (auto enemy : enemies)
	{
		delete enemy;
	}
}

void Game::Run(RenderWindow& window, int& selectedEnemyType)
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
			EnemySpawner(window, selectedEnemyType);
			Enemys(window);
			//UI Update
			resources.scoreText.setString("Score: " + to_string(player.GetScore()));
		}
		Draw(window);
	}
}

void Game::Menu(RenderWindow& window)
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
		}
		if (event.type == Event::KeyReleased)
		{
			if (event.key.code == Keyboard::Escape)
			{
				window.close();
			}
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
		if (bullets[i].GetShape().getGlobalBounds().intersects(enemies[k]->GetEnemyShape().getGlobalBounds()))
		{
			if (enemies[k]->GetHP() <= 1)
			{
				player.ScoreInc(enemies[k]->GetHPMax());
				enemies.erase(enemies.begin() + k);
			}
			else
			{
				--(*enemies[k]); //ENEMY TAKE DAMAGE
			}

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

void Game::EnemySpawner(RenderWindow& window, int& selectedEnemyType)
{
	//Enemy
	if (enemySpawnTimer < 25)
	{
		enemySpawnTimer++;
	}

	//enemy spawn
	if (enemySpawnTimer >= 25)
	{
		if (selectedEnemyType == 0)
		{
			enemies.push_back(new EnemyEasy(&resources.enemyTexEasy, window.getSize()));
		}
		else if (selectedEnemyType == 1)
		{
			enemies.push_back(new EnemyMedium(&resources.enemyTexMedium, window.getSize()));
		}
		else if (selectedEnemyType == 2)
		{
			enemies.push_back(new EnemyHard(&resources.enemyTexHard, window.getSize()));
		}
		enemySpawnTimer = 0; //reset timer
	}
}

void Game::Enemys(RenderWindow &window)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i]->Move(window);

		if (enemies[i]->GetEnemyShape().getPosition().x <= 0 - enemies[i]->GetEnemyShape().getGlobalBounds().width)
		{
			enemies.erase(enemies.begin() + i);
			break;
		}

		if (enemies[i]->GetEnemyShape().getGlobalBounds().intersects(player.GetPlayerShape().getGlobalBounds()))
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
		resources.eHpText.setString(to_string(enemies[i]->GetHP()) + "/" + to_string(enemies[i]->GetHPMax()));
		resources.eHpText.setPosition(enemies[i]->GetEnemyShape().getPosition().x, enemies[i]->GetEnemyShape().getPosition().y - resources.eHpText.getGlobalBounds().height + 15);
		window.draw(resources.eHpText);
		window.draw(enemies[i]->GetEnemyShape());
	}

	//UI
	window.draw(resources.scoreText);
	window.draw(resources.hpText);

	if (player.GetHP() <= 0)
	{
		resources.hpText.setString(to_string(player.GetHP()) + "/" + to_string(player.GetHPMax()));
		window.draw(resources.gameOverText);
		window.draw(resources.escapeMenu);
	}

	window.display();
}