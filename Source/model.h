#pragma once

#include <SFML/Graphics.hpp>
#define WINDOW_WIDTH 800
#define WINDOW_HIGHT 600
#include "Player.h"
#include "Enemy.h"
class Model
{

public:

	Model();
	~Model();
	void update(sf::Time);
	std::vector<Bullet*> bullets;
	std::vector<Bullet*> player_bullets;
	std::vector<Enemy*> enemies;
	sf::Texture bullet_texture;
	float timing;
	int stage;
	int score;
	Player p;

private:
	void updateBullets(sf::Time deltaTime);
	void updateEnemies(sf::Time deltaTime);
	//handles the spawning of enemies as the game proceeds.
	//Starts off with them spawning in specific locations, later on it changes to random spawinging.
	void updateStage(float i);
};
