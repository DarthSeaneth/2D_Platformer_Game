#include "main.h"

int main()
{

	//Camera, backgrounds, obstacles, and main bools

	sf::RenderWindow window(sf::VideoMode(1024, 768), "Final Project");
	window.setFramerateLimit(40);

	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("Textures/background.png");
	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(3, 4);

	sf::Sprite backgroundSprite2;
	backgroundSprite2.setTexture(backgroundTexture);
	backgroundSprite2.setScale(3, 4);
	backgroundSprite2.setPosition(1024, 0);

	sf::Sprite backgroundSprite3;
	backgroundSprite3.setTexture(backgroundTexture);
	backgroundSprite3.setScale(3, 4);
	backgroundSprite.setPosition(2048, 0);

	sf::View camera(sf::FloatRect(50, 50, 150, 150));
	camera.setSize(1024, 768);
	camera.setCenter(512, 384);

	bool isMovingLeft = false;
	bool isMovingRight = false;

	sf::Texture obstacleTexture;
	obstacleTexture.loadFromFile("Textures/gem.png");

	bool gameOver = false;

	bool win = false;

	sf::Texture spikeTexture;
	spikeTexture.loadFromFile("Textures/spike_ball.png");
	obstacle spike[10];
	float initialXPos1 = 4500;
	float initialYPos1 = 600;
	for (int i = 0; i < 10; i++)
	{
		spike[i] = obstacle(sf::Vector2f(initialXPos1, initialYPos1), &spikeTexture);
		initialXPos1 += 600;
		initialYPos1 -= 100;
	}

	//Default score

	int score = 0;

	//Texts

	sf::Text scoreText;
	sf::Font gameFont;
	gameFont.loadFromFile("Font/Candal.ttf");

	sf::Text gameOverText;
	gameOverText.setFont(gameFont);
	gameOverText.setString("\n\n\n\n\t\t\t\t\t You Died\n\t\t\t\t\tGame Over");
	gameOverText.setColor(sf::Color::Red);
	gameOverText.setCharacterSize(48);

	sf::Text winText;
	winText.setFont(gameFont);
	winText.setString("\n\n\n\n\t\t\t\t\t You Win");
	winText.setColor(sf::Color::Blue);
	winText.setCharacterSize(48);

	sf::Text exitText;
	exitText.setFont(gameFont);
	exitText.setString("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\  Press Space to Exit\n\t\t\t\t\t");
	exitText.setColor(sf::Color::White);
	exitText.setCharacterSize(36);

	scoreText.setFont(gameFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(28);
	scoreText.setColor(sf::Color::Red);

	//Gems

	obstacle gems[50];
	float initialXPos = 900;

	for (int i = 0; i < 50; i++) 
	{
		gems[i] = obstacle(sf::Vector2f(initialXPos, 695), &obstacleTexture);
		initialXPos += 150;
	}

	//Platforms

	sf::Texture platformTex;
	platformTex.loadFromFile("Textures/platform.png");
	platform thePlatform;
	platform thePlatform2;
	platform thePlatform3;
	platform thePlatform4;
	platform thePlatform5;

	bool touchedByAnAngel = false;

	thePlatform = platform(sf::Vector2f(1550, 525), &platformTex);
	thePlatform2 = platform(sf::Vector2f(1900, 400), &platformTex);
	thePlatform3 = platform(sf::Vector2f(2350, 350), &platformTex);
	thePlatform4 = platform(sf::Vector2f(2725, 225), &platformTex);
	thePlatform5 = platform(sf::Vector2f(3125, 200), &platformTex);

	player thePlayer;

	//enemy theEnemy;
	int base_h;
	egg dragonEgg;

	//Game events

	while (window.isOpen()) 
	{
		sf::Event event;

		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//Player movement

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::A)
				{
					isMovingLeft = true;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					isMovingRight = true;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::A)
				{
					isMovingLeft = false;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					isMovingRight = false;
				}
			}
			if (event.type == sf::Event::KeyPressed) 
			{
				if (event.key.code == sf::Keyboard::A)
					thePlayer.movingLeft = true;
			}

			if (event.type == sf::Event::KeyPressed) 
			{
				if (event.key.code == sf::Keyboard::D)
					thePlayer.movingRight = true;
			}

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					if (!thePlayer.jumping)
					{
						base_h = thePlayer.playerSprite.getPosition().y;
						thePlayer.jumpState = 1;
						thePlayer.jumping = true;
					}
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::A)
					thePlayer.movingLeft = false;
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::D)
					thePlayer.movingRight = false;
			}
		}
		sf::Vector2f movement(0, 0);

		if (thePlayer.playerSprite.getPosition().x < 100)
		{
			thePlayer.movingLeft = false;
		}
		if (thePlayer.playerSprite.getPosition().x > 3330)
		{
			thePlayer.movingRight = false;
		}

		if (thePlayer.movingLeft)
		{
			movement.x -= 5.1f;
		}

		if (thePlayer.movingRight)
		{
			movement.x += 5.1f;
		}
		

		thePlayer.playerSprite.move(movement);
		thePlayer.update(base_h);
		window.clear();

		//When player is alive

		if (!gameOver)
		{	
			window.draw(backgroundSprite);
			window.draw(backgroundSprite2);
			window.draw(backgroundSprite3);
			window.draw(thePlatform.platformSprite);
			window.draw(thePlatform2.platformSprite);
			window.draw(thePlatform3.platformSprite);
			window.draw(thePlatform4.platformSprite);
			window.draw(thePlatform5.platformSprite);
			window.draw(dragonEgg.eggSprite);
			for (int i = 0; i < 50; i++)
			{
				gems[i].update(3000);
				window.draw(gems[i].obstacleSprite);

				if (thePlayer.playerSprite.getGlobalBounds().intersects(gems[i].obstacleSprite.getGlobalBounds()))
				{
					gems[i].reposition(3000);
					score += 1000;
					scoreText.setString("Score: " + std::to_string(score));
				}
			}
			for (int i = 0; i < 10; i++)
			{
				spike[i].update(4500);
				window.draw(spike[i].obstacleSprite);
				if (spike[i].obstacleSprite.getPosition().x < 0||thePlayer.playerSprite.getGlobalBounds().intersects(spike[i].obstacleSprite.getGlobalBounds()))
				{
					spike[i].reposition(4500);
					gameOver = true;
				}
			}
			
			if (thePlayer.playerSprite.getGlobalBounds().intersects(thePlatform.platformSprite.getGlobalBounds()))
			{
				thePlayer.jumping = false;
				touchedByAnAngel = true;

			}
			else  if (thePlayer.playerSprite.getGlobalBounds().intersects(thePlatform2.platformSprite.getGlobalBounds()))
			{
				thePlayer.jumping = false;				
				touchedByAnAngel = true;

			}
			else if (thePlayer.playerSprite.getGlobalBounds().intersects(thePlatform3.platformSprite.getGlobalBounds()))
			{
				thePlayer.jumping = false;				
				touchedByAnAngel = true;

			}
			else if (thePlayer.playerSprite.getGlobalBounds().intersects(thePlatform4.platformSprite.getGlobalBounds()))
			{
				thePlayer.jumping = false;				
				touchedByAnAngel = true;

			}
			else if (thePlayer.playerSprite.getGlobalBounds().intersects(thePlatform5.platformSprite.getGlobalBounds()))
			{
				thePlayer.jumping = false;				
				touchedByAnAngel = true;

			}

			else if (touchedByAnAngel) {
				touchedByAnAngel = false;
				thePlayer.jumping = true;
			}
			
			//Camera movements

			sf::Vector2f viewMove(0, 0);
			if (camera.getCenter().x < 512)
			{
				isMovingLeft = false;
			}
			if (camera.getCenter().x > 2850)
			{
				isMovingRight = false;
			}
			if (isMovingLeft)
				viewMove.x -= 5.1;
			if (isMovingRight)
				viewMove.x += 5.1;

			camera.move(viewMove);
			window.setView(camera);

			scoreText.move(viewMove);

			gameOverText.move(viewMove);
			winText.move(viewMove);
			exitText.move(viewMove);

			window.draw(thePlayer.playerSprite);

			//window.draw(theEnemy.enemySprite);

			if (thePlayer.playerSprite.getGlobalBounds().intersects(dragonEgg.eggSprite.getGlobalBounds()))
			{
				win = true;
			}
		}

		//Win function

		if (win)
		{
			window.clear();
			window.draw(winText);
			window.draw(exitText);
			dragonEgg.eggSprite.setPosition(2650, 450);
			dragonEgg.eggSprite.setScale(1.7, 1.7);
			window.draw(dragonEgg.eggSprite);
			if (event.key.code == sf::Keyboard::Space)
			{
				break;
			}
			
		}

		//Death function

		else if(gameOver)
		{
			window.clear();
			window.draw(gameOverText);
			window.draw(exitText);
			if (event.key.code == sf::Keyboard::Space)
			{
				break;
			}
		}
		window.draw(scoreText);
		window.display();

		

	}
}
	