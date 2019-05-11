#include "Enemy_1.h"
#include <iostream>
#define WINDOW_WIDTH 588
#define WINDOW_HIGHT 600
Enemy_1::Enemy_1(int hight, int width, int i) :Enemy(hight,width)
{
	health = 20;
	radius = 15;
	//Changes the type and direction of the enemy based on the input variable i
	if (i == 0)
	{
		lenght1 = 1;
		length2 = 1;
		length3 = 3;
		xSpeed1 = 0;
		ySpeed1 = 2;
		xSpeed2 = 0;
		ySpeed2 = 0;
		xSpeed3 = -2;
		ySpeed3 = 0;
	}
	else
	{
		lenght1 = 1;
		length2 = 1;
		length3 = 3;
		xSpeed1 = 0;
		ySpeed1 = 2;
		xSpeed2 = 0;
		ySpeed2 = 0;
		xSpeed3 = 2;
		ySpeed3 = 0;
	}
	timer_2 = 0;
}

Enemy_1::Enemy_1(int x, int y, float speed, int angle) :Enemy(x,y,speed, angle)
{

}
Enemy_1::Enemy_1(int x, int y, int xSpeed, int ySpeed) :Enemy(x,y,xSpeed,ySpeed)
{

}
Enemy_1::~Enemy_1()
{}


void Enemy_1::update(sf::Time delta_time, int playerX, int playerY, std::vector<Bullet*> *bulls, std::vector<Bullet*> *player_bull)
{
	timer_2 += delta_time.asSeconds();
	if (timer_2 < lenght1)
	{
		//std::cout << "stage 1\n";
		x+=xSpeed1;
		y+=ySpeed1;
	}
	else if (timer_2<length2)
	{
		//std::cout << "stage 2\n";
		x += xSpeed2;
		y += ySpeed2;
	}
	else
	{
		//std::cout << "stage 3\n";
		x += xSpeed3;
		y += ySpeed3;
	}
	
	timer += delta_time.asSeconds();
	if (timer >= 1)
	{

		float f = getAngle(playerX, playerY);

		Bullet* temp = new Bullet(x, y);
		temp->speed = 4;
		temp->setVector(f);
		bulls->push_back(temp);
		temp = new Bullet(x, y);
		temp->speed = 4;
		temp->setVector(f + 20);
		bulls->push_back(temp);
		temp = new Bullet(x, y);
		temp->speed = 4;
		temp->setVector(f - 20);
		bulls->push_back(temp);
		timer = 0;
	}
	enemy_sprite.setPosition(x, y);
	Collision(player_bull);
	if (x < -30 || y < -30 || x>WINDOW_WIDTH + 30 || y>WINDOW_HIGHT + 30)
		should_exist = false;
}


void Enemy_1::Collision(std::vector<Bullet*> *player_bullets)
{
	std::vector<Bullet*>::iterator bulletIter;

	int i = 0;
		for (bulletIter = player_bullets->begin(); bulletIter < player_bullets->end(); bulletIter++, i++)
		{
						if (pow((this->x - (*bulletIter)->x), 2) + pow((this->y - (*bulletIter)->y), 2) - 2 <= pow((this->radius + (*bulletIter)->radius), 2))
			{
				
				(*bulletIter)->should_exist = false;

				health--;
				std::cout << "hit me\n";
				if (health <= 0)
				{
					
					destroyed = true;
					should_exist = false;
				}

			}
		}
	
}