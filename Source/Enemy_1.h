#pragma once
#include "Enemy.h"
class Enemy_1 : public Enemy
{
public:
	Enemy_1(int hight, int width, int i);
	Enemy_1(int x, int y, float speed, int angle);
	Enemy_1(int x, int y, int xSpeed, int ySpeed);
	~Enemy_1();
	int stage;
	int max_stage;
	float timer_2;
	float lenght1;
	float length2;
	float length3;

	float xSpeed1;
	float xSpeed2;
	float xSpeed3;
	float ySpeed1;
	float ySpeed2;
	float ySpeed3;
	//void update(sf::Time delta_time);
	virtual void update(sf::Time delta_time, int playerX, int playerY, std::vector<Bullet*> *bulls, std::vector<Bullet*> *player_bull);
	void Collision(std::vector<Bullet*> *player_bullets);
	
};