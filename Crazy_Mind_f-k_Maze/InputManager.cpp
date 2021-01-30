#include "InputManager.h"

bool InputManager::shouldMoveUp()
{
	return m_moveUp;
}

bool InputManager::shouldMoveDown()
{
	return m_moveDown;
}

bool InputManager::shouldMoveLeft()
{
	return m_moveLeft;
}

bool InputManager::shouldMoveRight()
{
	return m_moveRight;
}

void InputManager::update(sf::Event& t_event)
{
	controller.update(); 

	m_moveUp = controller.m_currentState.leftThumbStick.y > 0 || (t_event.KeyPressed && 
		(t_event.key.code == sf::Keyboard::W));

	m_moveDown = controller.m_currentState.leftThumbStick.y < 0 || (t_event.KeyPressed &&
		(t_event.key.code == sf::Keyboard::S));

	m_moveLeft = controller.m_currentState.leftThumbStick.x < 0 || (t_event.KeyPressed &&
		(t_event.key.code == sf::Keyboard::A));

	m_moveRight = controller.m_currentState.leftThumbStick.x > 0 || (t_event.KeyPressed &&
		(t_event.key.code == sf::Keyboard::D));

	m_rotateLeft = controller.m_currentState.leftB || (t_event.KeyPressed &&
		(t_event.key.code == sf::Keyboard::Q));

	m_rotateRight = controller.m_currentState.rightB || (t_event.KeyPressed &&
		(t_event.key.code == sf::Keyboard::E));

	m_jumping = (controller.m_currentState.a || (t_event.KeyPressed &&
		(t_event.key.code == sf::Keyboard::Space))) && ! m_jumping;

	if (m_jumping)
	{
		playersYPos = 60; // PLACEHOLDER - please find a way to add the players current y position here!
	}


	if (t_event.type == sf::Event::KeyReleased)
	{
		if (t_event.key.code == sf::Keyboard::W)
		{
			m_moveUp = false;
		}
		if (t_event.key.code == sf::Keyboard::A)
		{
			m_moveLeft = false;
		}
		if (t_event.key.code == sf::Keyboard::D)
		{
			m_moveRight = false;
		}
		if (t_event.key.code == sf::Keyboard::S)
		{
			m_moveDown = false;
		}
		if (t_event.key.code == sf::Keyboard::Q)
		{
			m_rotateLeft = false;
		}
		if (t_event.key.code == sf::Keyboard::E)
		{
			m_rotateRight = false;
		}
	}

	if (controller.m_currentState.leftThumbStick.y >= 0 && controller.m_previousState.leftThumbStick.y < 0)
	{
		m_moveUp = false;
	}

	if (controller.m_currentState.leftThumbStick.y <= 0 && controller.m_previousState.leftThumbStick.y > 0)
	{
		m_moveDown = false;
	}

	if (controller.m_currentState.leftThumbStick.x <= 0 && controller.m_previousState.leftThumbStick.x > 0)
	{
		m_moveRight = false;
	}

	if (controller.m_currentState.leftThumbStick.x >= 0 && controller.m_previousState.leftThumbStick.x < 0)
	{
		m_moveLeft = false;
	}

	if (controller.m_currentState.leftB && !controller.m_previousState.leftB)
	{
		m_rotateLeft = false;
	}

	if (controller.m_currentState.rightB && !controller.m_previousState.rightB)
	{
		m_rotateRight = false;
	}

	if (playersYPos <= floor)
	{
		m_jumping = false;
	}
}

InputManager::InputManager() : m_moveDown{ false },
m_moveLeft{ false },
m_moveRight{ false },
m_moveUp{ false }, m_rotateLeft{ false }, m_rotateRight{ false }, m_jumping{ false }
{
}
