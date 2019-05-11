#include "Bullet.h"
#include <iostream>
#define WINDOW_WIDTH 588
#define WINDOW_HIGHT 600
#define PI 3.1415926535897
Bullet::Bullet()
{
	sf::Image unmasked;

	unmasked.loadFromFile("Assets/Bullets/blue bull.png");
	unmasked.createMaskFromColor(sf::Color::Black);
	bullet_texture.loadFromImage(unmasked);
	bullet.setTexture(bullet_texture);
	should_exist = true;
	x = 0;
	y = 0;
	bullet.setPosition(x, y);
	bullet.setOrigin(9, 9);
	radius = 9;
}

Bullet::Bullet(int x, int y)
{
	sf::Image unmasked;

	unmasked.loadFromFile("Assets/Bullets/blue bull.png");
	unmasked.createMaskFromColor(sf::Color::Black);
	bullet_texture.loadFromImage(unmasked);
	bullet.setTexture(bullet_texture);
	bullet.setOrigin(9, 9);
	bullet.setPosition(x, y);
	radius = 9;
	should_exist = true;
	this->x = x;
	this->y = y;

}

Bullet::Bullet(int x, int y, sf::Texture *text)
{
	bullet.setTexture(*text);
	bullet.setOrigin(9,9);
	radius = 9;
	bullet.setPosition(x, y);
	should_exist = true;
	this->x = x;
	this->y = y;
}

Bullet::Bullet(int x, int y, int xSpeed, int ySpeed)
{
	sf::Image unmasked;

	unmasked.loadFromFile("Assets/Bullets/blue bull.png");
	unmasked.createMaskFromColor(sf::Color::Black);
	bullet_texture.loadFromImage(unmasked);
	bullet.setTexture(bullet_texture);
	bullet.setOrigin(9, 9);
	bullet.setPosition(x, y);
	should_exist = true;
	radius = 9;
	this->x = x;
	this->y = y;

	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
	

}

Bullet::~Bullet()
{

}

void Bullet::setVector(int angle)
{
	//sets the vector speed from an angle
	this->xSpeed = speed*cos(angle *PI / 180.0);
	this->ySpeed = speed*sin(angle* PI / 180.0);
}

void Bullet::update(sf::Time delta_time)
{
	x += xSpeed *(delta_time.asSeconds() *60);
	y += ySpeed *(delta_time.asSeconds()*60);
	bullet.setPosition(x, y);
	//std::cout << "x:"<<x <<" y:"<< y << std::endl;
	if (x < -20 || y < -20|| x>WINDOW_WIDTH+20|| y>WINDOW_HIGHT+20)
		should_exist = false;
}
