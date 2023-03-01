#include "main.h"

player::player() : player::player(sf::Vector2f(100, 660), "Textures/dragon.png") {
}

player::player(sf::Vector2f position, std::string texFileLoc) 
{
	playerTexture.loadFromFile(texFileLoc);

	playerSprite.setTexture(playerTexture);
	playerSprite.setOrigin(15, 16);
	playerSprite.setScale(0.8, 0.8);
	playerSprite.setPosition(position.x, position.y);


	movingLeft = false;
	movingRight = false;
	jumping = false;
	jumpState = 0;

}

void player::update(int y)
{

	if (jumping)
	{
		if (jumpState == 1)
		{
			if (playerSprite.getPosition().y > y-300)
			{
				playerSprite.move(0, -10);
			}
			else {
				jumpState = 2;
			}
		}
	else if (jumpState == 2)
	{
		if (playerSprite.getPosition().y < 660)
		{
			playerSprite.move(0, 10);
		}
		else {
			jumpState = 0;
			jumping = false;
		}
	}
	}
}
