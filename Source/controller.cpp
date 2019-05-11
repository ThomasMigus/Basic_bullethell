#include "controller.h"
#define SPEED 5

Controller::Controller(Model* model, View* view)
{
	this->model = model;
	this->view = view;
}

void Controller::inputs(sf::Time delta_time)
{

	sf::Event event;

	while (this->view->window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				this->view->window.close();
				break;

		}
	}
	model->p.inputs(delta_time, &model->player_bullets);

}