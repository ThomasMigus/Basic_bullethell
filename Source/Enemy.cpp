#include "Enemy.h"
#include <iostream>
#define WINDOW_WIDTH 588
#define WINDOW_HIGHT 600
#define PI 3.1415926535897


Enemy::Enemy(int x, int y)
{
	sf::Image unmasked;

	unmasked.loadFromFile("Assets/Kenny/space shooter/PNG/ufoBlue.png");
	unmasked.createMaskFromColor(sf::Color::Black);
	enemy_texture.loadFromImage(unmasked);
	enemy_sprite.setTexture(enemy_texture);
	enemy_sprite.setPosition(x, y);
	enemy_sprite.setOrigin(45.5, 45.5);
	enemy_sprite.setScale(0.5, 0.5);
	should_exist = true;
	destroyed = false;
	speed=10;
	timer = 0;
	setVector(0);
	this->x = x;
	this->y = y;
}
Enemy::Enemy(int x, int y, float speed, int angle)
{
	sf::Image unmasked;
	timer = 0;
	unmasked.loadFromFile("Assets/Kenny/space shooter/PNG/ufoBlue.png");
	unmasked.createMaskFromColor(sf::Color::Black);
	enemy_texture.loadFromImage(unmasked);
	enemy_sprite.setTexture(enemy_texture);
	enemy_sprite.setPosition(x, y);
	enemy_sprite.setOrigin(45.5, 45.5);
	enemy_sprite.setScale(0.5, 0.5);
	should_exist = true;
	destroyed = false;
	this->speed = speed;
	setVector(angle);
	this->x = x;
	this->y = y;
}

Enemy::Enemy(int x, int y, int xSpeed, int ySpeed)
{
	sf::Image unmasked;
	timer = 0;
	unmasked.loadFromFile("Assets/Kenny/space shooter/PNG/ufoBlue.png");
	unmasked.createMaskFromColor(sf::Color::Black);
	enemy_texture.loadFromImage(unmasked);
	enemy_sprite.setTexture(enemy_texture);
	enemy_sprite.setPosition(x, y);
	enemy_sprite.setOrigin(45.5, 45.5);
	enemy_sprite.setScale(0.5, 0.5);
	should_exist = true;
	destroyed = false;
	this->x = x;
	this->y = y;
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
}

Enemy::~Enemy()
{

}

void Enemy::setVector(int angle)
{
	//sets the vector speed from an angle
	this->xSpeed = speed*cos(angle *PI / 180.0);
	this->ySpeed = speed*sin(angle* PI / 180.0);
}

void Enemy::update(sf::Time delta_time)
{
	x += xSpeed *(delta_time.asSeconds() * 60);
	y += ySpeed *(delta_time.asSeconds() * 60);
	timer += delta_time.asSeconds();
	enemy_sprite.setPosition(x, y);
	if (x < -10 || y < -10 || x>WINDOW_WIDTH + 10 || y>WINDOW_HIGHT + 10)
		should_exist = false;
}

void Enemy::update(sf::Time delta_time, int playerX, int playerY, std::vector<Bullet*> *bulls,std::vector<Bullet*> *player_bulls)
{
	x += xSpeed *(delta_time.asSeconds() * 60);
	y += ySpeed *(delta_time.asSeconds() * 60);
	timer += delta_time.asSeconds();
	if (timer >= 1)
	{

		float f = getAngle(playerX, playerY);

		Bullet* temp = new Bullet(x, y);
		temp->speed = 4;
		temp->setVector(f);
		bulls->push_back(temp);
		temp= new Bullet(x, y);
		temp->speed = 4;
		temp->setVector(f+20);
		bulls->push_back(temp);
		temp = new Bullet(x, y);
		temp->speed = 4;
		temp->setVector(f - 20);
		bulls->push_back(temp);
		timer = 0;
	}
	enemy_sprite.setPosition(x,y);
	if (x < -10 || y < -10 || x>WINDOW_WIDTH + 10 || y>WINDOW_HIGHT + 10)
		should_exist = false;
}

float Enemy::getAngle(int xT, int yT)
{

	int xD = xT - x;
	int yD = yT - y;
	if (xD == 0&&yD<0)
	{
		return 270;
	}
	else if (xD == 0)
	{
		return 90;
	}
	else if (yD == 0&&xD>0)
	{
		return 0;
	}
	else if (yD==0)
	{
		return 180;
	}
	
	float temp = atan(abs(yD)*1.0/ abs(xD));
	temp = temp * 180 / PI;


		
	if (xD > 0 && yD > 0)
	{
		return temp;
	}
	else if (xD > 0 && yD < 0)
	{
		return 90-temp - 90;
	}
	else if (xD < 0 && yD >0)
	{
		return 90-temp + 90;
	}
	else if (xD < 0 && yD < 0)
	{
		return temp + 180;
	}
}