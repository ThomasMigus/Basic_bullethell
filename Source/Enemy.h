#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
class Enemy
{
public:
	Enemy(int hight, int width);
	Enemy(int x, int y, float speed, int angle);
	Enemy(int x, int y, int xSpeed, int ySpeed);
	~Enemy();
	int x, y, radius;
	float speed;
	int xSpeed;
	int ySpeed;
	bool should_exist;
	bool destroyed;
	sf::Sprite enemy_sprite;
	sf::Texture enemy_texture;
	int health;
	

	float timer;
	virtual void update(sf::Time delta_time);
	virtual void update(sf::Time delta_time, int playerX, int playerY, std::vector<Bullet*> *bulls, std::vector<Bullet*> *player_bulls);
	void setVector(int angle);


	float getAngle(int,int);

};

