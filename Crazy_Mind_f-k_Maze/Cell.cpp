#include "Cell.h"

Cell::Cell()
{
	loadTextures();
}

int Cell::typeOfCell()
{
	return typeOfCellData;
}

void Cell::setUpFrame(int rectLeft, int rectTop, int rectWidth, int rectHeight)
{
	sprite.setTexture(levelTetxure);
	levelFrame = sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight);
	sprite.setTextureRect(levelFrame);
	sprite.setOrigin(levelFrame.width / 2, levelFrame.height / 2);
	sprite.setPosition(100.0f, 1500.0f);
}


sf::Sprite Cell::getSprite()
{
	return sprite;
}

void Cell::loadTextures()
{
	//make empty tile the normal black screen
	if (!levelTetxure.loadFromFile("Assets/Images/ice.png"))
	{
		std::cout << "error with empty cell image file";
	}

}

