#ifndef GAME_H
#define GAME_h


#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include "MyVector3.h"
#include "Xbox360Controller.h"
#include "ltbl/lighting/LightSystem.h"

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
	void shaderSetUp();

	sf::RenderWindow m_renderWin;
	Xbox360Controller m_gameControllerPad;

	sf::RectangleShape RoomOne;
	float RoomSize;
	int outlineThickness;

	sf::View view;

	Player m_player;

	sf::Shader unshadowShader;
	sf::Shader lightOverShapeShader;

	sf::Vector2f center;

	sf::Texture penumbraTexture;
	sf::Texture Point;
	sf::Sprite penumbraSprite;

	ltbl::LightSystem ls;
	std::shared_ptr<ltbl::LightPointEmission> light = std::make_shared<ltbl::LightPointEmission>();
};
#endif // !GAME_H