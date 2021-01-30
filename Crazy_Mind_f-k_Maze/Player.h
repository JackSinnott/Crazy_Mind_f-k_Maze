#pragma once

#include <SFML/Graphics.hpp>
#include "InputManager.h"

class Player
{
public:
	Player();

	void draw(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);

	void processEvents(sf::Event t_event);
private:
	sf::RectangleShape m_shape;
	sf::Vector2f m_movement;

	int m_speed;

	InputManager m_manager;
};

