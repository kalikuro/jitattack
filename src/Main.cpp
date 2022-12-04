// main file for game

#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include <time.h>
#include <random>

#include "Platform/Platform.hpp"
#include "movement.hpp"
#include "shoot.hpp"

int main(void)
{

	int screenWidth = 1280;
	int screenHeight = 720;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Jit Attack", sf::Style::Close | sf::Style::Titlebar);
	sf::Event event;

	// loading in a sprite
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (!playerTexture.loadFromFile("content/playerSprite.png"))
	{
		// error
		return EXIT_FAILURE;
	}
	playerTexture.setSmooth(true);
	playerTexture.setRepeated(false);
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(sf::Vector2f(float(screenWidth) / 5000, float(screenHeight) / 2500));
	playerSprite.setOrigin(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2);
	playerSprite.setPosition(screenWidth / 2, screenHeight / 2);

	while (window.isOpen()){

		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Texture background;
		background.loadFromFile("content/gamebg.png");

		window.clear();
		window.draw(sf::Sprite(background));
		window.draw(playerSprite);

		// movement
		Movement movement;
		movement.moveSprite(playerSprite);
		movement.wrapSprite(playerSprite, window);

		// shoot
		// Shoot shoot;
		// shoot.onShoot(playerSprite, window);

		window.display();
	}

	return 0;
}
