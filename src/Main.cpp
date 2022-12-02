// main file for game

#include <SFML/Graphics.hpp>
#include <math.h>
#include <vector>
#include <time.h>
#include <random>


#include "zombie.h"
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

	// Spawning zombies
	// zombie zombieArray[25];
	// for(int i = 0; i < 25; i++){
	// 	zombie zombie(9.8f);
	// 	zombieArray[i] = zombie;
	// }

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
		Shoot shoot;
		shoot.onShoot(playerSprite, window);

		zombie zombie;
		for(int i = 0; i < 25; i++){
			// sf::Vector2f zombiePos = zombie.getSprite().getPosition();
			// sf::Vector2f playerPos = playerSprite.getPosition();
			// float distance = sqrt(pow((zombiePos.x - playerPos.x), 2) + pow((zombiePos.y - playerPos.y), 2));
			// if(distance < 100){
			// 	zombie.kill();
			// }
			// if(zombie.isAlive()){
			// 	zombie.draw(window);
			// }

			sf::Vector2f zombiePos = zombie.getSprite().getPosition();
			for(int i = 0; i < 25; i++){
				zombiePos = sf::Vector2f(rand() % 1280, rand() % 720);
				zombie.setLocation(zombiePos.x, zombiePos.y);
				zombie.draw(window);
			}

		}

		window.display();
	}

	return 0;
}
