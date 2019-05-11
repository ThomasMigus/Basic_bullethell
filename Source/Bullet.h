#pragma once
#include <SFML/Graphics.hpp>



class Bullet
{
public:
	Bullet();
	Bullet(int,int);
	Bullet(int,int,sf::Texture*);
	Bullet(int,int,int,int);
	~Bullet();

	
	void update(sf::Time delta_time);
	void setVector(int);
	float x;
	float y;
	float speed;
	float radius;
	float xSpeed;
	float ySpeed;

	sf::Sprite bullet;
	sf::Texture bullet_texture;
	bool should_exist;
private:	
	
};