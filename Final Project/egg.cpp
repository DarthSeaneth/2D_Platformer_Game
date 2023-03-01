#include "main.h"

egg::egg() : egg::egg(sf::Vector2f(3200, 140), "Textures/dragon_egg.png")
{}

egg::egg(sf::Vector2f position, std::string texFileLoc)
{
	eggTexture.loadFromFile(texFileLoc);

	eggSprite.setTexture(eggTexture);
	eggSprite.setScale(0.35, 0.35);
	eggSprite.setPosition(position.x, position.y);
}