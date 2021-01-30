#pragma once

#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "Levels/LevelLoader.h"

class Player
{
public:
	Player();

	void draw(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime);

	void processEvents(sf::Event t_event);

	void setUpSprites();
private:
	sf::RectangleShape m_shape;
	sf::Vector2f m_movement;

	// To store the game level data.
	LevelData m_level;

	// Player image 
	sf::Sprite m_playerSprite;
	sf::Texture m_playerTexture;

	sf::IntRect m_playerFrame;

	sf::Vector2f m_velocity;
	sf::Vector2f m_position;

	sf::Vector2f m_previousPos;

	int m_speed;

	InputManager m_manager;
};

