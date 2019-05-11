#include "view.h"

#include <iostream>


View::View(Model* model)
{

	this->model = model;

	this->window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HIGHT), "COMP2501_DEMO_07_(Animated Sprites)");
	
	this->window.setFramerateLimit(60);

	sf::Image unmasked;
	
	unmasked.loadFromFile("Assets/ansimuz/top-down-river-files/PNG/background.png");
	this->background_tex.loadFromImage(unmasked);
	background_spri.setTexture(background_tex);
	background_spri2.setTexture(background_tex);
	background_spri2.setPosition(0, 600);
	background_spri2.setScale(2.3, 1.875);
	background_spri.setPosition(0, 0);
	background_spri.setScale(2.3, 1.875);
	
	unmasked.loadFromFile("Assets/clouds/cloud4.png");
	unmasked.createMaskFromColor(sf::Color(129, 177, 217));
	cloud1_tex.loadFromImage(unmasked);
	cloud1_spri.setTexture(cloud1_tex);
	cloud1_spri.setScale(0.3, 0.3);
	cloud1_spri.setPosition(50,0);

	unmasked.loadFromFile("Assets/clouds/cloud2.png");
	unmasked.createMaskFromColor(sf::Color(129, 177, 217));
	cloud2_tex.loadFromImage(unmasked);
	cloud2_spri.setTexture(cloud2_tex);
	cloud2_spri.setScale(0.18, 0.18);
	cloud2_spri.setPosition(250, 200);

	unmasked.loadFromFile("Assets/clouds/cloud3.png");
	unmasked.createMaskFromColor(sf::Color(129, 177, 217));
	cloud3_tex.loadFromImage(unmasked);
	cloud3_spri.setTexture(cloud3_tex);
	cloud3_spri.setScale(0.18, 0.18);
	cloud3_spri.setPosition(150, 500);


	font.loadFromFile("Assets/timeburnernormal.ttf");
	score.setFont(font);
	score.setCharacterSize(30);
	score.setStyle(sf::Text::Bold);
	score.setFillColor(sf::Color::White);

	lives.setFont(font);
	lives.setCharacterSize(30);
	lives.setStyle(sf::Text::Bold);
	lives.setFillColor(sf::Color::Red);

	gameOver.setFont(font);
	gameOver.setCharacterSize(50);
	gameOver.setStyle(sf::Text::Bold);
	gameOver.setFillColor(sf::Color::Red);
	gameOver.setOutlineThickness(10);
	gameOver.setOutlineColor(sf::Color::Black);
	gameOver.setString("GAME OVER");
	gameOver.setPosition(300, 250);
	scoreboard.setFillColor(sf::Color::Black);
	scoreboard.setSize(sf::Vector2f(218,600));
	scoreboard.setPosition(588, 0);
}

void View::render(sf::Time deltaTime,float elapsed)
{
	
	this->window.clear();
	if (model->p.health > 0)
	{
		//the transformations handle the scrolling of the background
		//Somewhat magic numbers, will need to be changed if the screen size is, but fixed screensize is assumed in this instance.
		int transform = -600 + ((int)((elapsed / 5.0) * 600)) % 600;
		int transform2 = ((int)((elapsed / 5.0) * 600)) % 600;
		background_spri2.setPosition(0, transform);
		background_spri.setPosition(0, transform2);
		window.draw(background_spri2);
		window.draw(background_spri);

		//handles rendering of clouds and enemies
		RenderClouds(deltaTime);
		RenderEntities();
		window.draw(scoreboard);
		lives.setString("Lives: " + std::to_string(model->p.health));
		lives.setPosition(600, 50);
		window.draw(lives);

		score.setString("Score: " + std::to_string(model->score));
		score.setPosition(600, 100);
		window.draw(score);
		this->window.draw(model->p.player_sprite);
	}
	else
	{
		window.draw(gameOver);
	}
	this->window.display();

}

void View::RenderClouds(sf::Time deltaTime)
{
	
	if (cloud1_spri.getPosition().y > 700)
	{
		cloud1_spri.setPosition(cloud1_spri.getPosition().x, -150);
	}
	else
	{
		cloud1_spri.setPosition(cloud1_spri.getPosition().x, cloud1_spri.getPosition().y+3*deltaTime.asSeconds()*60);
	}
	if (cloud2_spri.getPosition().y > 700)
	{
		cloud2_spri.setPosition(cloud2_spri.getPosition().x, -150);
	}
	else
	{
		cloud2_spri.setPosition(cloud2_spri.getPosition().x, cloud2_spri.getPosition().y + 3 * deltaTime.asSeconds() * 60);
	}
	if (cloud3_spri.getPosition().y > 700)
	{
		cloud3_spri.setPosition(cloud3_spri.getPosition().x, -150);
	}
	else
	{
		cloud3_spri.setPosition(cloud3_spri.getPosition().x, cloud3_spri.getPosition().y + 3 * deltaTime.asSeconds() * 60);
	}
	window.draw(cloud1_spri);
	window.draw(cloud2_spri);
	window.draw(cloud3_spri);
}
void View::RenderEntities()
{
	
		std::vector<Bullet*>::iterator bulletIter;
		for (bulletIter = model->bullets.begin(); bulletIter < model->bullets.end(); bulletIter++)
		{
			if ((*bulletIter)->x > -10 && (*bulletIter)->y > -10 && (*bulletIter)->x < WINDOW_WIDTH + 10 && (*bulletIter)->y < WINDOW_HIGHT + 10)
			{
				this->window.draw((*bulletIter)->bullet);
			}
		}
		for (bulletIter = model->player_bullets.begin(); bulletIter < model->player_bullets.end(); bulletIter++)
		{
			if ((*bulletIter)->x > -10 && (*bulletIter)->y > -10 && (*bulletIter)->x < WINDOW_WIDTH + 10 && (*bulletIter)->y < WINDOW_HIGHT + 10)
			{
				this->window.draw((*bulletIter)->bullet);
			}
		}
		
		std::vector<Enemy*>::iterator EnemyIter;
		for (EnemyIter = model->enemies.begin(); EnemyIter < model->enemies.end(); EnemyIter++)
		{
			if ((*EnemyIter)->x > -10 && (*EnemyIter)->y > -10 && (*EnemyIter)->x < WINDOW_WIDTH + 10 && (*EnemyIter)->y < WINDOW_HIGHT + 10)
			{

				this->window.draw((*EnemyIter)->enemy_sprite);
			}
		}
}