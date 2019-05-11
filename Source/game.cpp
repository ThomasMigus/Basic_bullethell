#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "game.h"


Game::Game()
{

	model = new Model();
	view = new View(model);
	controller = new Controller(model, view);

}

Game::~Game()
{ }


void Game::loop()
{

	sf::Time delta_time;
	
	/*
	This loops until the window is closed
	*/
	while (this->view->window.isOpen())
	{
		//This game utilizes delta time. This means the game speed is not tied to framerate.
		delta_time = this->clock.restart();

		if (model->p.health > 0)
		{
			this->controller->inputs(delta_time);
			this->model->update(delta_time);
		}
		this->view->render(delta_time,clock2.getElapsedTime().asSeconds());


	}

	this->view->window.close();

}