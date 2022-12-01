// main file for game

#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>

#include "Platform/Platform.hpp"
#include "movement.hpp"
#include "shoot.hpp"

// float deltaTime(){
// 	static sf::Clock clock;
// 	static sf::Time time;
// 	static sf::Time oldTime;
// 	time = clock.getElapsedTime();
// 	float dt = (time.asSeconds() - oldTime.asSeconds());
// 	oldTime = time;
// 	return dt;
// }

int main(void)
{

	int screenWidth = 1280;
	int screenHeight = 720;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Jit Attack", sf::Style::Close | sf::Style::Titlebar);
	sf::Event event;

	int randomXPos = 1 + (rand() % 1280);
	int randomYPos = 1 + (rand() % 720);
	// zombie sprite
	sf::Texture zombieTexture;
	sf::Sprite zombieSprite;

	if (!zombieTexture.loadFromFile("content/zombie_sprite.png"))
	{
		return EXIT_FAILURE;
	}
	zombieTexture.setSmooth(true);
	zombieTexture.setRepeated(false);
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setScale(sf::Vector2f(float(screenWidth) / 3500, float(screenHeight) / 1750));
	zombieSprite.setOrigin(zombieTexture.getSize().x / 2, zombieTexture.getSize().y / 2);
	zombieSprite.setPosition(randomXPos, randomYPos);

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


	// playerSprite.setPosition(sf::Vector2f((screenWidth / 2 ) - ((playerTexture.getSize().x * playerSprite.getScale().x) / 2), (screenHeight / 2) - ((playerTexture.getSize().y * playerSprite.getScale().y) / 2)));


	while (window.isOpen()){

		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Texture background;
		background.loadFromFile("content/gamebg.png");

		window.clear();
		window.draw(sf::Sprite(background));
		window.draw(sf::Sprite(zombieSprite));
		window.draw(playerSprite);

		// movement
		Movement movement;
		movement.moveSprite(playerSprite);
		movement.wrapSprite(playerSprite, window);

		// shoot
		Shoot shoot;
		shoot.onShoot(playerSprite, window);

		window.display();
	}

	return 0;
}
