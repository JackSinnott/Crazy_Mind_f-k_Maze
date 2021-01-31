#include "Game.h"
// Contructor

Game::Game() :
	m_renderWin{ sf::VideoMode{ 768, 768, 1 }, "Crazy_Maze" }
{
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

	if (!m_bgTexture.loadFromFile(m_level.m_background.m_fileName))
	{
		std::cout << "Error loading background image" << std::endl;
	}

	m_bgSprite.setTexture(m_bgTexture);
	RoomSize = 600.0f;
	outlineThickness = 25;
	RoomOne.setFillColor(sf::Color::Transparent);
	RoomOne.setSize({ RoomSize, RoomSize });
	RoomOne.setOutlineThickness(outlineThickness);
	RoomOne.setOutlineColor(sf::Color::White);

	RoomOne.setOrigin({ RoomOne.getPosition().x + RoomOne.getGlobalBounds().width / 2 - outlineThickness,
						RoomOne.getPosition().y + RoomOne.getGlobalBounds().height / 2 - outlineThickness });

	RoomOne.setPosition(m_renderWin.getSize().x / 2,
						m_renderWin.getSize().y / 2);

	view.setCenter(RoomOne.getPosition());
}

/// Destructor
Game::~Game()
{
}

// Loop designed to work at equal speed on all PCs
// If a PC is slower, it will update the same amount of times
// And render less often
void Game::run()
{
	sf::Clock gameClock;											// Game clock
	sf::Time timeTakenForUpdate = sf::Time::Zero;					// No lag on first input
	sf::Time timePerFrame = sf::seconds(1.f / 60.f);				// 60 frames per second
	while (m_renderWin.isOpen())									// Loop
	{
		processInput();												// Check for input
		timeTakenForUpdate += gameClock.restart();					// Returns time take to do the loop
		while (timeTakenForUpdate > timePerFrame)					// Update enough times to catch up on updates missed during the lag time
		{
			timeTakenForUpdate -= timePerFrame;						// Decrement lag
			processInput();											// More checks, more accuracte input to display will be
			update(timePerFrame);									// Update
		}
		render();
	}
}


// Process PC input
void Game::processInput()
{
	sf::Event event;
	
	while (m_renderWin.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			m_renderWin.close();
		}
		if (sf::Event::KeyPressed == event.type)
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_renderWin.close();
			}
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
		}
		m_player.processEvents(event);
	}	
}


// Updates Game
void Game::update(sf::Time t_deltaTime)
{
	m_player.update(t_deltaTime);

	//view.setRotation(view.getRotation() + 1.0f);

	m_player.update(t_deltaTime);

}

// Renders
void Game::render()
{
	m_renderWin.clear();
	m_renderWin.draw(m_bgSprite);
	m_player.draw(m_renderWin);

	// Kiernens Camera and Room
	m_renderWin.setView(view);
	m_renderWin.draw(RoomOne);

	m_player.draw(m_renderWin);

	m_renderWin.display();
}

void Game::intialize()
{
}