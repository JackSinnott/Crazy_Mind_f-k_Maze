#pragma once
#include <SFML/Graphics.hpp>
#include "Xbox360Controller.h"
class InputManager
{
private:
	/// <summary>
	/// store if the player should move either up, down, left or right
	/// </summary>
	bool m_moveUp;
	bool m_moveDown;
	bool m_moveLeft;
	bool m_moveRight;
	bool m_rotateLeft;
	bool m_rotateRight;
	bool m_jumping;

	Xbox360Controller controller;
	int playersYPos = 300; // PLACEHOLDER - please find a way to add the players current y position here!

	int floor = 300; // PLACEHOLDER - please change so floor is for each level!!
public:
	/// <summary>
	/// each of these functions just returns the correspondin member variable of the class
	/// </summary>
	/// <returns>a bool that states if the can move in that direction</returns>
	bool shouldMoveUp();
	bool shouldMoveDown();
	bool shouldMoveLeft();
	bool shouldMoveRight();
	/// <summary>
	/// checks for keypresses and updates if the player should move in any of the directions
	/// </summary>
	/// <param name="t_event"></param>
	void update(sf::Event& t_event);
public:
	/// <summary>
	/// default constructor
	/// </summary>
	InputManager();

};

