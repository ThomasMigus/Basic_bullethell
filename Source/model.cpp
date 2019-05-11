#include "model.h"
#include <iostream>
#include <stack>
#include "Enemy_1.h"
Model::Model() :p(200,200)
{
	sf::Image unmasked;
	
	unmasked.loadFromFile("Assets/Bullets/blue bull.png");
	unmasked.createMaskFromColor(sf::Color::Black);
	bullet_texture.loadFromImage(unmasked);
	stage = 0;
	score = 0;

}

Model::~Model()
{ }

void Model::update(sf::Time deltaTime)
{
	timing += deltaTime.asSeconds();
	p.update(deltaTime,&bullets);
	updateBullets(deltaTime);
	updateEnemies(deltaTime);
	updateStage(timing);
}

void Model::updateBullets(sf::Time deltaTime)
{
	std::vector<Bullet*>::iterator bulletIter;
	std::stack <int> pops;
	int count = 0;
	for (bulletIter = bullets.begin(); bulletIter < bullets.end(); bulletIter++)
	{
		(*bulletIter)->update(deltaTime);
		//std::cout << "Updating" << std::endl;
		if ((*bulletIter)->should_exist == false)
		{
			pops.push(count);
		}
		count++;
	}
	Bullet* temp;
	for (int i = pops.size(); i > 0; i--)
	{
		temp = bullets.at(pops.top());
		bullets.erase(bullets.begin()+pops.top());
		delete temp;
		pops.pop();
	}
	count = 0;
	for (bulletIter = player_bullets.begin(); bulletIter < player_bullets.end(); bulletIter++)
	{
		(*bulletIter)->update(deltaTime);

		if ((*bulletIter)->should_exist == false)
		{
			pops.push(count);
		}
		count++;
	}
	for (int i = pops.size(); i > 0; i--)
	{
		temp = player_bullets.at(pops.top());
		player_bullets.erase(player_bullets.begin() + pops.top());
		delete temp;
		pops.pop();
	}
}
/*
Updates the enemies
removes enemies from the list that should be destroyed.
*/
void Model::updateEnemies(sf::Time deltaTime) 
{
	std::vector<Enemy*>::iterator EnemyIter;
	std::stack <int> pops;
	int count = 0;
	for (EnemyIter = enemies.begin(); EnemyIter < enemies.end(); EnemyIter++)
	{
		(*EnemyIter)->update(deltaTime,p.x,p.y,&bullets,&player_bullets);
		if ((*EnemyIter)->should_exist == false)
		{
			pops.push(count);
			if ((*EnemyIter)->destroyed == true)
			{
				score += 20;
			}
		}
		count++;
	}
	Enemy* temp;
	for (int i = pops.size(); i > 0; i--)
	{
		temp = enemies.at(pops.top());
		enemies.erase(enemies.begin() + pops.top());
		delete temp;
		pops.pop();
		std::cout << "removed\n";
	}
}

//Starts off with them spawning in specific locations, later on it changes to random spawinging.
// Input, i, a variable denoting seconds
void Model::updateStage(float seconds)
{
	if (seconds > 3&&stage==0)
	{
		enemies.push_back(new Enemy_1(50,10,1));
		enemies.push_back(new Enemy_1(533, 10, 0));
		stage = 1;
	}
	else if (seconds > 6 && stage == 1)
	{
		enemies.push_back(new Enemy_1(50, 10, 1));
		enemies.push_back(new Enemy_1(533, 10, 0));
		enemies.push_back(new Enemy_1(90, 10, 1));
		enemies.push_back(new Enemy_1(573, 10, 0));
		stage = 2;
	}
	else if (seconds > 9 && stage == 2)
	{
		enemies.push_back(new Enemy_1(50, 10, 1));
		enemies.push_back(new Enemy_1(533, 10, 0));
		enemies.push_back(new Enemy_1(90, 10, 1));
		enemies.push_back(new Enemy_1(573, 10, 0));
		enemies.push_back(new Enemy_1(10, 10, 1));
		enemies.push_back(new Enemy_1(493, 10, 0));
		stage = 3;
	}
	else if (seconds > 14 && stage == 3)
	{
		
		enemies.push_back(new Enemy_1(rand()%530+20, 10, rand()%2));

		timing = 13;
	}
}