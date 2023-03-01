#include "main.h"

obstacle::obstacle(){}

obstacle::obstacle(sf::Vector2f position, sf::Texture* obstacleTexture) 
{
	obstacleSprite.setTexture(*obstacleTexture);
	obstacleSprite.setScale(0.045, 0.045);
	obstacleSprite.setPosition(position.x, position.y);

	srand(time(NULL));
}

void obstacle::update(int x)
{
	obstacleSprite.move(-7.5, 0);
	if (obstacleSprite.getPosition().x < 0)
	{
		obstacleSprite.setPosition(x,
			obstacleSprite.getPosition().y);
	}
}

void obstacle::reposition(int x)
{
	obstacleSprite.setPosition(sf::Vector2f(x, randomizeYPos()));
}

int obstacle::randomizeYPos()
{
	int randomY;
	int thePosition = 0;
	randomY = rand() % 9;
	if (randomY == 0)
	{
		thePosition = 650;
	}
	else if (randomY == 1)
	{
		thePosition = 550;
	}
	else if (randomY == 2)
	{
		thePosition = 600;
	}
	else if (randomY == 3)
	{
		thePosition = 550;
	}
	else if (randomY == 4)
	{
		thePosition = 575;
	}
	else if (randomY == 5)
	{
		thePosition = 600;
	}
	else if (randomY == 6)
	{
		thePosition = 625;
	}
	else if (randomY == 7)
	{
		thePosition = 575;
	}
	else if (randomY == 8)
	{
		thePosition = 575;
	}
	return thePosition;
}
