#pragma once

#include "model.h"
#include "view.h"

class Controller
{

public:

	Model* model;
	View* view;

	Controller(Model* model, View* view);
	~Controller();

	void inputs(sf::Time);

};
