#include "Game.h"

// Contructor
Game::Game() :
	m_renderWin{ sf::VideoMode{ 768, 768, 1 }, "Crazy_Maze" }
{

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
	}
	m_player.processEvents(event);
	
}

// Updates Game
void Game::update(sf::Time t_deltaTime)
{
	m_gameControllerPad.update();
	m_player.update(t_deltaTime);
}

// Renders
void Game::render()
{
	m_renderWin.clear();
	m_player.draw(m_renderWin);
	m_renderWin.display();
}

void Game::intialize()
{
}