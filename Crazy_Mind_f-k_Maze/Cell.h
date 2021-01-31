#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Cell
{
public:
	int typeOfCellData;       //is the cell empty or contain a pellet or a wall ?
		//0 could represent an empty cell, 1 a pellet and 2 a wall.

	sf::Texture levelTetxure;
	sf::Sprite sprite; 	   //sprite used to represent the cell


public:
	Cell();
	int typeOfCell();
	void setUpFrame(int retLeft, int rectTop, int rectWidth, int rectHeight);

	sf::Sprite getSprite();
	sf::IntRect levelFrame;

	void loadTextures();
	inline void setPosition(sf::Vector2f t_pos) { sprite.setPosition(t_pos); }
};