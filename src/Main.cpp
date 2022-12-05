// main file for game

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <vector>
#include <time.h>
#include <random>


#include "zombie.h"
#include "Platform/Platform.hpp"
#include "movement.hpp"
#include "shoot.hpp"
#include "menu.h"

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

	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Jit Attack", sf::Style::Close | sf::Style::Titlebar);
	sf::Event event;

	// loading in a sprite
	sf::Texture playerTexture;
	sf::Sprite playerSprite;


	// include audio
	sf::SoundBuffer buffer;
	sf::SoundBuffer buffer1;

	if(!buffer.loadFromFile("content/Never_See_Me_Again_V1.ogg")){
		std::cout << "Error loading sound" << std::endl;
	}
	if(!buffer1.loadFromFile("content/Where_He_Get_It.ogg")){
		std::cout << "Error loading sound" << std::endl;
	}
	sf::Sound sound;
	int random = rand();
	// pick randomly between buffer and buffer1
	if (random % 2 == 0){
		sound.setBuffer(buffer);
		sound.play();
	}
	else{
		sound.setBuffer(buffer1);
		sound.play();
	}

	Menu menu(window.getSize().x, window.getSize().y);

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
			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}

		sf::Texture background;
		//background.loadFromFile("content/gamebg.png");

		window.clear();

		menu.draw(window);

		window.draw(sf::Sprite(background));
		window.draw(playerSprite);


		// movement
		Movement movement;
		movement.moveSprite(playerSprite);
		movement.wrapSprite(playerSprite, window);

		// shoot
		Shoot shoot;
		shoot.onShoot(playerSprite, window);

		// zombie zombie;
		// sf::Vector2f zombiePos = zombie.getSprite().getPosition();
		// for(int i = 0; i < 25; i++){
		// 	zombiePos = sf::Vector2f(rand() % 1280, rand() % 720);
		// 	zombie.setLocation(zombiePos.x, zombiePos.y);
		// 	zombie.draw(window);
		// }


		window.display();
	}

	return 0;
}
