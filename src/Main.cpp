// main file for game

#include <SFML/Graphics.hpp>
#include "Platform/Platform.hpp"
#include <math.h>
#include <iostream>
#include "movement.hpp"


// float deltaTime(){
// 	static sf::Clock clock;
// 	static sf::Time time;
// 	static sf::Time oldTime;
// 	time = clock.getElapsedTime();
// 	float dt = (time.asSeconds() - oldTime.asSeconds());
// 	oldTime = time;
// 	return dt;
// }

int main(void){

	int screenWidth = 1280;
	int screenHeight = 720;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Jit Attack", sf::Style::Close | sf::Style::Titlebar);
	sf::Event event;

	// loading in a sprite
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if(!playerTexture.loadFromFile("content/playerSprite.png")){
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

		window.clear();
		window.draw(playerSprite);

		// movement
		Movement movement;
		movement.moveSprite(playerSprite);
		movement.wrapSprite(playerSprite, window);

		window.display();
	}

	return 0;
}
