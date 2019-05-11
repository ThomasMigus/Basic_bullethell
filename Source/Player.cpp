#include "Player.h"
#include <cstdlib>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include "bullet.h"
#include <iostream>
#define WINDOW_WIDTH 588
#define WINDOW_HIGHT 600
#define PLAYER_SPEED 6

Player::Player(int x, int y)
{
	
	this->radius = 15;

	sf::Image unmasked;
	
	unmasked.loadFromFile("Assets/Kenny/space shooter/PNG/playerShip1_blue.png");
	player_texture.loadFromImage(unmasked);
	player_sprite.setTexture(player_texture);
	player_sprite.setPosition(x, y);
	player_sprite.setOrigin(49, 37.5);
	player_sprite.setScale(0.5, 0.5);
	health = 5;
	radius = 10;
	inv = false;
	this->x = x;
	this->y = y;
}

Player::~Player()
{

}

void Player::inputs(sf::Time delta_time, std::vector<Bullet*>* bullets)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (x - PLAYER_SPEED >= 49)
		{
			x -= PLAYER_SPEED*(delta_time.asSeconds() * 60);

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (x + PLAYER_SPEED <=WINDOW_WIDTH - 49)
		{
			x += PLAYER_SPEED*(delta_time.asSeconds() * 60);

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (y - PLAYER_SPEED >= 37.5)
		{
			y -= PLAYER_SPEED*(delta_time.asSeconds() * 60);

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (y + PLAYER_SPEED <= WINDOW_HIGHT - 37.5)
		{
			y += PLAYER_SPEED*(delta_time.asSeconds() * 60);

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{

		bullets->push_back(new Bullet(x+20, y, 0, -20));
		bullets->push_back(new Bullet(x-20, y, 0, -20));

	}
}

void Player::update(sf::Time deltaTime, std::vector<Bullet*>* bullets)
{
	
	std::vector<Bullet*>::iterator bulletIter;

	int i = 0;
	bool b = false;
	//checks for collisions
	if (inv == false)
	{
		for (bulletIter = bullets->begin(); bulletIter < bullets->end(); bulletIter++, i++)
		{
			//std::cout << pow((this->x - (*bulletIter)->x), 2) + pow((this->y - (*bulletIter)->y), 2) - 2<<" is less than or equal to"<< pow((this->radius + (*bulletIter)->radius), 2) <<std::endl;

			if (pow((this->x - (*bulletIter)->x), 2) + pow((this->y - (*bulletIter)->y), 2) - 2 <= pow((this->radius + (*bulletIter)->radius), 2))
			{
				
				std::cout << "here" << std::endl;
				(*bulletIter)->should_exist = false;

				inv == true;
				health--;
				clock = 0;

			}
		}
	}
	else
	{
		clock += deltaTime.asSeconds();
		if (clock > 3)
		{
			inv = false;
		}
	}
	//sets the position after the changes
	this->player_sprite.setPosition(sf::Vector2f(x, y));
	//this->hitbox.setPosition(sf::Vector2f(x + 8, y + 8));
}
/*
void Player::update()
{
	this->player_sprite.setPosition(sf::Vector2f(x, y));
}*/

void Player::draw(sf::RenderWindow*  w)
{
	//w->draw(player_sprite);
}