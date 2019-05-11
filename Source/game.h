#pragma once
#include <SFML/Graphics.hpp>

#include "model.h"
#include "view.h"
#include "controller.h"

class Game
{

public:
	

	Model* model;
	View* view;
	Controller* controller;

	Game();
	~Game();

	void loop();
	
	sf::Clock clock;
	sf::Clock clock2;
};