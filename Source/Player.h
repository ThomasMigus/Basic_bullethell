#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
//#include "Model.h"
class Player
{
public:
	Player(int hight, int width);
	~Player();
	int x, y, radius;

	sf::Sprite player_sprite;
	sf::Texture player_texture;
	int health;
	bool inv;
	float clock;
	void update(sf::Time,std::vector<Bullet*>* bullets);
	//void update();
	void inputs(sf::Time delta_time, std::vector<Bullet*>*);
	void draw(sf::RenderWindow*  w);
	


};

