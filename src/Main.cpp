#include "Platform/Platform.hpp"

int main()
{
	util::Platform platform;

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());

	// Use the screenScalingFactor
	window.create(sf::VideoMode(800 * screenScalingFactor, 600 * screenScalingFactor), "Jit Attack");
	platform.setIcon(window.getSystemHandle());


	// 17 - 21 ... 
	sf::Texture texture;
	if (!texture.loadFromFile("content/temp.png")){
		return EXIT_FAILURE;
	}
	sf::Sprite sprite(texture);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		// this line will
		window.draw(sprite);
		window.display();
	}

	return 0;
}
