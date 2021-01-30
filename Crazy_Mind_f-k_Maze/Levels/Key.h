#pragma once
#include "SFML/Graphics.hpp"
// Known bug: Their is no initialised texture so the address is pointing to nothing
class Key
{
private:
	sf::Texture m_keyTexture;
	sf::Sprite keyBody;
	bool playerFoundIt = false;
public:
	Key(sf::Vector2f location);
	void load(sf::Texture& texture);
	void gotPickedUp();
	bool playerHasKey();

};

