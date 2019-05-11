#pragma once

#include "updateable.hpp"

#include "player.hpp"

class Trigger : public Updateable
{

public:

	Trigger();

	void update(sf::Time);

	bool is_triggered;

	sf::Time timer;
	//or you could use a collection of potential objects for collision, or whatever

};