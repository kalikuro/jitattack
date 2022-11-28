// main file for game

#include <SFML/Graphics.hpp>
#include "Platform/Platform.hpp"

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
	playerSprite.setPosition(sf::Vector2f((screenWidth / 2 ) - ((playerTexture.getSize().x * playerSprite.getScale().x) / 2), (screenHeight / 2) - ((playerTexture.getSize().y * playerSprite.getScale().y) / 2)));

	while (window.isOpen()){

		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// move player sprite
		// move player up/north
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			playerSprite.move(0, -.25);
		}
		// move player down/south
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			playerSprite.move(-.25, 0);
		}
		// move player left/west
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			playerSprite.move(0, .25);
		}
		// move player right/east
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			playerSprite.move(.25, 0);
		}


		window.clear();

		// this line will draw the sprite
		window.draw(playerSprite);

		window.display();
	}

	return 0;
}

