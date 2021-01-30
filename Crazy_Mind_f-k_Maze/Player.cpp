#include "Player.h"

Player::Player() : m_speed{75}
{
	m_shape.setSize(sf::Vector2f(50, 50));
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setPosition(sf::Vector2f(300, 500));
  
	int currentLevel = 1;
	try
	{
		LevelLoader::load(currentLevel, m_level);
	}
	catch (std::exception& e)
	{
		std::cout << "Level Loading failure." << std::endl;
		std::cout << e.what() << std::endl;
		throw e;
	}

	setUpSprites();
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


void Player::setUpSprites()
{
	if (!m_playerTexture.loadFromFile(m_level.m_background.m_fileName))
	{
		std::cout << "Error loading background image" << std::endl;
	}
	m_playerSprite.setTexture(m_playerTexture);
	m_playerFrame = sf::IntRect(295, 167, 130, 130);
	m_playerSprite.setTextureRect(m_playerFrame);
	m_playerSprite.setPosition(m_position);
	m_playerSprite.setOrigin(m_playerFrame.width / 2, m_playerFrame.height / 2);
	m_playerSprite.setScale(1.0f, 1.0f);
}

