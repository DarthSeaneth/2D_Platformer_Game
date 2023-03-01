#pragma once
#include <string>
#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Clock.hpp>

using namespace std;

class player 
{
public:

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	bool movingRight;
	bool movingLeft;
	bool jumping;
	int jumpState;

	player();
	player(sf::Vector2f position, std::string texFileLoc);

	void update(int y);

private:
};

class enemy
{
public:

	sf::Texture enemyTexture;
	sf::Sprite enemySprite;

	enemy();
	enemy(sf::Vector2f position, std::string texFileLoc);

private:
};

class obstacle
{
public:

	sf::Texture obstacleTexture;
	sf::Sprite obstacleSprite;
	float yPos;

	obstacle();
	obstacle(sf::Vector2f position, sf::Texture* obstacleTexture);

	void update(int x);
	void reposition(int x);
	int randomizeYPos();

private:
};

class platform
{
public:

	sf::Texture platformTexture;
	sf::Sprite platformSprite;

	platform();
	platform(sf::Vector2f position, sf::Texture* platformTexture);

private:
};

class egg
{
public:

	sf::Texture eggTexture;
	sf::Sprite eggSprite;

	egg();
	egg(sf::Vector2f position, std::string texFileLoc);

private:
};

class fireball
{
public:


	fireball();
private:
};

