#include "Game.h"

// Contructor
Game::Game() :
	m_renderWin{ sf::VideoMode{ 768, 768, 1 }, "Crazy_Maze" }
{
	intialize();	
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
	m_gameControllerPad.update();

	view.setRotation(view.getRotation() + 1.0f);

	m_player.update(t_deltaTime);

}

// Renders
void Game::render()
{
	m_renderWin.clear();

	// Kiernens Camera and Room
	m_renderWin.setView(view);
	m_renderWin.draw(RoomOne);
	m_player.draw(m_renderWin);
	ls.render(view, unshadowShader, lightOverShapeShader);

	m_renderWin.display();
}

void Game::intialize()
{
	center = sf::Vector2f{ m_renderWin.getSize().x / 2.0f,	m_renderWin.getSize().y / 2.0f };
	RoomSize = 600.0f;
	outlineThickness = 25;
	RoomOne.setFillColor(sf::Color::Transparent);
	RoomOne.setSize({ RoomSize, RoomSize });
	RoomOne.setOutlineThickness(outlineThickness);
	RoomOne.setOutlineColor(sf::Color::White);

	RoomOne.setOrigin({ RoomOne.getPosition().x + RoomOne.getGlobalBounds().width / 2 - outlineThickness,
						RoomOne.getPosition().y + RoomOne.getGlobalBounds().height / 2 - outlineThickness });

	RoomOne.setPosition(center);

	view.setCenter(RoomOne.getPosition());
}

void Game::shaderSetUp()
{
	if (!unshadowShader.loadFromFile("resources/unshadowShader.vert", "resources/unshadowShader.frag"))
	{
		std::cout << "Shit dont work" << std::endl;
	}

	if(!lightOverShapeShader.loadFromFile("resources/lightOverShapeShader.vert", "resources/lightOverShapeShader.frag"))
	{
		std::cout << "Other shit dont work" << std::endl;
	}

	penumbraTexture.loadFromFile("resources / penumbraTexture.png");
	penumbraTexture.setSmooth(true);
	penumbraSprite.setTexture(penumbraTexture);
	penumbraSprite.setPosition(center);

	Point.loadFromFile("ASSETS/Images/Point_Light.png");
	Point.setSmooth(true);

	ls.create(sf::FloatRect(-1000.0f, -1000.0f, 1000.0f, 1000.0f), m_renderWin.getSize(), penumbraTexture, unshadowShader, lightOverShapeShader);

	light->emissionSprite.setOrigin(RoomOne.getPosition().x - RoomOne.getGlobalBounds().width / 0.7f,
									RoomOne.getPosition().y - RoomOne.getGlobalBounds().height / 0.7f);

	light->emissionSprite.setTexture(Point);
	light->emissionSprite.setColor(sf::Color::White);
	light->emissionSprite.setPosition(center);
	light->localCastCenter = sf::Vector2f(0.0f, 0.0f);

	ls.addLight(light);
}