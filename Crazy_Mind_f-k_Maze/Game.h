#ifndef GAME_H
#define GAME_h


#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Levels/LevelLoader.h"

#include "MyVector3.h"

#include "Player.h"

class Game
{
public:
	Game();
	~Game();

	void run();

protected:

	void intialize();
	void update(sf::Time t_deltaTime);
	void processInput();
	void render();

	// Background image 
	sf::Sprite m_bgSprite;
	sf::Texture m_bgTexture;

	std::vector<sf::Sprite> m_floorSprites;
	sf::Sprite floorSprite;

	// To store the game level data.
	LevelData m_level;

	sf::RenderWindow m_renderWin;

	sf::RectangleShape RoomOne;
	float RoomSize;
	int outlineThickness;

	sf::View view;

	Player m_player;
};


#endif // !GAME_H



