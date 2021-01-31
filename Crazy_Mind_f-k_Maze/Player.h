#pragma once

#include <SFML/Graphics.hpp>
#include "Levels/LevelLoader.h"
#include "AnimatedSprite.h"
#include "MyVector3.h"
#include "Xbox360Controller.h"

class Player
{
public:
	Player();

	void draw(sf::RenderWindow& t_window);
	void update(sf::Time t_deltaTime, Xbox360Controller* t_cont);

	void setUpSprites();

	void checkInput(Xbox360Controller* t_cont);
	void move(MyVector3 t_movement);
	void setPosition(sf::Vector2f pos);
	AnimatedSprite* getBody();
	sf::Vector2f getPosition();

	void fixBooleans();

private:
	//sf::RectangleShape m_shape;
	sf::Vector2f m_movement;

	// To store the game level data.
	LevelData m_level;

	// Player image 
	AnimatedSprite m_playerSprite;
	sf::Texture m_playerTexture;

	Animation idle;
	Animation jump;
	Animation run;
	Animation land;

	sf::Vector2f m_velocity;
	sf::Vector2f m_position;

	sf::Vector2f m_previousPos;

	int m_speed;

	bool walkLeft{ false };
	bool walkRight{ false };
	bool rotateRight{ false };
	bool rotateLeft{ false };
};

