// main file for game

#include <SFML/Graphics.hpp>
#include "Platform/Platform.hpp"

int main(void){

	int screenWidth = 800;
	int screenHeight = 600;

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
	playerSprite.setPosition(sf::Vector2f(screenWidth / 2, screenHeight / 2));

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		// this line will draw the sprite
		window.draw(playerSprite);

		window.display();
	}

	return 0;
}

