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

void Player::update(sf::Time t_deltaTime, Xbox360Controller* t_cont)
{
	m_position = m_playerSprite.getPosition();

	/*if (m_manager.shouldJump() && 
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
	}*/

	m_playerSprite.setPosition(m_position);
	checkInput(t_cont);

	
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

void Player::checkInput(Xbox360Controller* t_cont)
{
	if (t_cont->m_currentState.dPadRight == true || t_cont->m_currentState.leftThumbStick.x > 50 || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
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
	if (t_cont->m_currentState.dPadLeft == true || t_cont->m_currentState.leftThumbStick.x < -50 || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
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

	if (t_cont->m_currentState.a == true && t_cont->m_previousState.a != true || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_velocity = m_velocity + sf::Vector2f(0, -500);

	}
	if (t_cont->m_currentState.rTrigger > 50 && t_cont->m_previousState.rTrigger < 50 || sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		// insert rotation code	
	}
	if (t_cont->m_currentState.lTrigger < -50 && t_cont->m_previousState.lTrigger > -50 || sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		//insert rotation code
	}
	t_cont->m_previousState = t_cont->m_currentState;
}

void Player::move(MyVector3 t_movement)
{
	m_previousPos = m_position;
	m_position = m_position + sf::Vector2f{ t_movement };
}

void Player::setPosition(sf::Vector2f pos)
{
	m_position = pos;
}


AnimatedSprite* Player::getBody()
{
	return &m_playerSprite;
}

sf::Vector2f Player::getPosition()
{
	return m_playerSprite.getPosition();
}


void Player::fixBooleans()
{
	walkLeft = false;
	walkRight = false;
}
