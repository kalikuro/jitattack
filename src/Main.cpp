// main file for game

#include <SFML/Graphics.hpp>
#include "Platform/Platform.hpp"

int main()
{
	// util::Platform platform;

	// // in Windows at least, this must be called before creating the window
	// float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());

	// // Use the screenScalingFactor
	// window.create(sf::VideoMode(800 * screenScalingFactor, 600 * screenScalingFactor), "Jit Attack");
	// platform.setIcon(window.getSystemHandle());

	int screenWidth = 800;
	int screenHeight = 600;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Jit Attack");
	sf::Event event;
	sf::Texture texture;
	sf::Sprite playerSprite;

	// 17 - 21 ... Texture loading for sprite
	if (!texture.loadFromFile("content/playerSprite.png")){
		return EXIT_FAILURE;
	}

	texture.setSmooth(true);
	texture.setRepeated(false);
	playerSprite.setTexture(texture);
	playerSprite.setPosition(0, 0);

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

