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
	m_moveUp = t_event.KeyPressed && (t_event.key.code == sf::Keyboard::W || t_event.key.code == sf::Keyboard::Up);
	m_moveDown = t_event.KeyPressed && (t_event.key.code == sf::Keyboard::S || t_event.key.code == sf::Keyboard::Down);
	m_moveLeft = t_event.KeyPressed && (t_event.key.code == sf::Keyboard::A || t_event.key.code == sf::Keyboard::Left);
	m_moveRight = t_event.KeyPressed && (t_event.key.code == sf::Keyboard::D || t_event.key.code == sf::Keyboard::Right);

	if (t_event.type == sf::Event::KeyReleased)
	{
		if (t_event.key.code == sf::Keyboard::W || t_event.key.code == sf::Keyboard::Up)
		{
			m_moveUp = false;
		}
		if (t_event.key.code == sf::Keyboard::A || t_event.key.code == sf::Keyboard::Left)
		{
			m_moveLeft = false;
		}
		if (t_event.key.code == sf::Keyboard::D || t_event.key.code == sf::Keyboard::Right)
		{
			m_moveRight = false;
		}
		if (t_event.key.code == sf::Keyboard::S || t_event.key.code == sf::Keyboard::Down)
		{
			m_moveDown = false;
		}
	}
}

InputManager::InputManager() : m_moveDown{ false },
m_moveLeft{ false },
m_moveRight{ false },
m_moveUp{ false }
{
}
