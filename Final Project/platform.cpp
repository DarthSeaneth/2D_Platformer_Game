#include "main.h"

platform::platform(){}

platform::platform(sf::Vector2f position, sf::Texture* platformTexture) 
{
	platformSprite.setTexture(*platformTexture);
	platformSprite.setScale(0.8, 0.8);
	platformSprite.setPosition(position.x, position.y);
}
