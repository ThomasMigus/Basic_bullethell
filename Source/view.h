#pragma once

#include "model.h"

#include <SFML/Graphics.hpp>

class View
{

public:

	sf::RenderWindow window;
	
	Model* model;
	/* 
	Function: View constructor
	Input: Takes a pointer to the model
	Output: None

	Handles the inputing of the sprites, textures and other resources needed to set up the view.
	*/
	View(Model* model);
	~View();

	/*
	variables for drawing the scene.
	*/
	sf::Texture background_tex;
	sf::Texture cloud1_tex;
	sf::Texture cloud2_tex;
	sf::Texture cloud3_tex;
	sf::Sprite background_spri;
	sf::Sprite background_spri2;
	sf::Sprite cloud1_spri;
	sf::Sprite cloud2_spri;
	sf::Sprite cloud3_spri;
	
	sf::RectangleShape scoreboard;
	sf::Font font;
	sf::Text score;
	sf::Text lives;
	sf::Text gameOver;
	//main render method
	void render(sf::Time,float);

private:
	//sub render methods, called by render
	void RenderClouds(sf::Time);

	/* Function: RenderEntities
	Input: None
	Output: None
	Renders the bullets and enemies to the screen.
	*/
	void RenderEntities();
};
