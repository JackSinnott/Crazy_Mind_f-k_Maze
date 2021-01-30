#include "Player.h"

Player::Player() : m_speed{75}
{
	m_shape.setSize(sf::Vector2f(50, 50));
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setPosition(sf::Vector2f(300, 500));
}

void Player::draw(sf::RenderWindow& t_window)
{
	t_window.draw(m_shape);
}

void Player::update(sf::Time t_deltaTime)
{
	if (m_manager.shouldMoveUp())
	{
		m_shape.setPosition(m_shape.getPosition() + sf::Vector2f(0.0f, -2.0f));
	}

	if (m_manager.shouldMoveDown())
	{
		m_shape.setPosition(m_shape.getPosition() + sf::Vector2f(0.0f, 2.0f));
	}

	if (m_manager.shouldMoveLeft())
	{
		m_shape.setPosition(m_shape.getPosition() + sf::Vector2f(-2.0f, 0.0f));
	}

	if (m_manager.shouldMoveRight())
	{
		m_shape.setPosition(m_shape.getPosition() + sf::Vector2f(2.0f, 0.0f));
	}
}

void Player::processEvents(sf::Event t_event)
{
	m_manager.update(t_event);
}
