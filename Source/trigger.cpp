#include "trigger.hpp"

Trigger::Trigger()
{

	this->position.x = 500;
	this->position.y = 300;
	this->is_triggered = false;
	this->timer = sf::seconds(5);

}

void Trigger::update(sf::Time deltaTime)
{

	if (is_triggered == false)
	{
		if (this->timer.asSeconds() > 0)
		{
			this->timer -= deltaTime;
		}
		else
		{
			this->is_triggered = true;
		}
	}

}

