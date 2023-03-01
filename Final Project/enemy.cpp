#include "main.h"

enemy::enemy() : enemy::enemy(sf::Vector2f(810, 640), "Textures/enemyknight.png") {
}

enemy::enemy(sf::Vector2f position, std::string texFileLoc) 
{
	enemyTexture.loadFromFile(texFileLoc);
	enemySprite.setTexture(enemyTexture);
	enemySprite.setOrigin(15, 16);
	enemySprite.setScale(0.5, 0.5);
	enemySprite.setPosition(position.x, position.y);
}

