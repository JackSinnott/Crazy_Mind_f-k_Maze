#include "Key.h"

Key::Key(sf::Vector2f location)
{
	// Load texture from Resource manager
	keyBody.setPosition(location);
}

void Key::load(sf::Texture& texture)
{
}

void Key::gotPickedUp()
{
	playerFoundIt = true;
}

bool Key::playerHasKey()
{
	return playerFoundIt;
}
