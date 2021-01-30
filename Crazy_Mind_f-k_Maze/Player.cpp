#include "Player.h"

Player::Player() : m_speed{75}
{
	//m_shape.setSize(sf::Vector2f(50, 50));
	//m_shape.setFillColor(sf::Color::Red);
	//m_shape.setPosition(sf::Vector2f(300, 500));
  
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
	//t_window.draw(m_shape);
	t_window.draw(m_playerSprite);
}

void Player::update(sf::Time t_deltaTime)
{
	m_position = m_playerSprite.getPosition();

	if (m_manager.shouldJump() && 
		m_playerSprite.getAnimation()->getFrame(0) != jump.getFrame(0))
	{
		m_playerSprite.setAnimation(jump);
		m_playerSprite.play();
		m_playerSprite.setLooped(false);
	}

	else if (m_manager.shouldMoveUp())
	{
		m_playerSprite.setPosition(m_position + sf::Vector2f(0.0f, -2.0f));

		if (m_playerSprite.getAnimation()->getFrame(0) == idle.getFrame(0))
		{
			m_playerSprite.setAnimation(run);
			m_playerSprite.play();
			m_playerSprite.setLooped(true);
		}
	}

	else if (m_manager.shouldMoveDown())
	{
		m_playerSprite.setPosition(m_position + sf::Vector2f(0.0f, 2.0f));

		if (m_playerSprite.getAnimation()->getFrame(0) == idle.getFrame(0))
		{
			m_playerSprite.setAnimation(run);
			m_playerSprite.play();
			m_playerSprite.setLooped(true);
		}
	}

	else if (m_manager.shouldMoveLeft())
	{
		m_playerSprite.setScale(4.0f, 4.0f);
		m_playerSprite.setPosition(m_position + sf::Vector2f(-2.0f, 0.0f));

		if (m_playerSprite.getAnimation()->getFrame(0) == idle.getFrame(0))
		{
			m_playerSprite.setAnimation(run);
			m_playerSprite.play();
			m_playerSprite.setLooped(true);
		}
	}

	else if (m_manager.shouldMoveRight())
	{
		m_playerSprite.setScale(-4.0f, 4.0f);
		m_playerSprite.setPosition(m_position + sf::Vector2f(2.0f, 0.0f));

		if (m_playerSprite.getAnimation()->getFrame(0) == idle.getFrame(0))
		{
			m_playerSprite.setAnimation(run);
			m_playerSprite.play();
			m_playerSprite.setLooped(true);
		}
	}

	else if (m_playerSprite.getAnimation()->getFrame(0) != idle.getFrame(0) && 
		m_playerSprite.getAnimation()->getFrame(0) != jump.getFrame(0))
	{
		m_playerSprite.setAnimation(idle);
		m_playerSprite.play();
		m_playerSprite.setLooped(true);
	}

	m_playerSprite.update(t_deltaTime);
}

void Player::processEvents(sf::Event t_event)
{
	m_manager.update(t_event);
}


void Player::setUpSprites()
{
	if (!m_playerTexture.loadFromFile(m_level.m_player.m_fileName))
	{
		std::cout << "Error loading background image" << std::endl;
	}

	m_position = sf::Vector2f(300, 500);

	idle.addFrame(sf::IntRect(5, 33, 20, 31));
	idle.addFrame(sf::IntRect(37, 33, 20, 31));
	idle.addFrame(sf::IntRect(69, 33, 20, 31));
	idle.addFrame(sf::IntRect(101, 33, 20, 31));

	run.addFrame(sf::IntRect(5, 64, 20, 31));
	run.addFrame(sf::IntRect(37, 64, 20, 31));
	run.addFrame(sf::IntRect(69, 64, 20, 31));
	run.addFrame(sf::IntRect(101, 64, 20, 31));

	jump.addFrame(sf::IntRect(197, 0, 20, 31));
	jump.addFrame(sf::IntRect(165, 0, 20, 31));
	jump.addFrame(sf::IntRect(133, 0, 20, 31));
	jump.addFrame(sf::IntRect(101, 0, 20, 31));
	jump.addFrame(sf::IntRect(69, 0, 20, 31));
	jump.addFrame(sf::IntRect(37, 0, 20, 31));
	jump.addFrame(sf::IntRect(5, 0, 20, 31));

	idle.setSpriteSheet(m_playerTexture);
	run.setSpriteSheet(m_playerTexture);
	jump.setSpriteSheet(m_playerTexture);
	
	m_playerSprite.setAnimation(idle);
	m_playerSprite.setPosition(m_position);
	m_playerSprite.setOrigin(idle.getFrame(0).width / 2, idle.getFrame(0).height / 2);
	m_playerSprite.setScale(4.0f, 4.0f);
	m_playerSprite.setLooped(true);
	m_playerSprite.play();
}

