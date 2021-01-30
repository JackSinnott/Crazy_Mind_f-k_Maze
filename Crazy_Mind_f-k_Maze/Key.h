#pragma once
#include "SFML/Graphics.hpp"
class Key
{
private:
	sf::Texture& m_keyTexture;
	sf::Sprite keyBody;
	bool playerFoundIt = false;
public:
	Key(sf::Vector2f location);
	void gotPickedUp();
	bool playerHasKey();

};

