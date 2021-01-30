#ifndef GAME_H
#define GAME_h


#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "MyVector3.h"
#include "Xbox360Controller.h"

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

	sf::RenderWindow m_renderWin;
	Xbox360Controller m_gameControllerPad;

	sf::RectangleShape RoomOne;
	float RoomSize;
	int outlineThickness;

	sf::View view;

	Player m_player;
};


#endif // !GAME_H



