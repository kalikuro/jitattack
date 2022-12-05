// // main file for game

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include <time.h>
#include <random>
#include "Platform/Platform.hpp"

class Bullet{
	public:
		sf::CircleShape shape;
		sf::Vector2f currVelocity;
		float maxSpeed;

		Bullet(float radius = 5.f) : currVelocity(0.f, 0.f), maxSpeed(12.f){
			this->shape.setRadius(radius);
			this->shape.setFillColor(sf::Color::White);
		}
};

int main(void){
	srand(time(NULL));

	int screenWidth = 1280;
	int screenHeight = 720;

	int spawnCounter = 0;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Jit Attack", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
	sf::Event event;

	// loading in a sprite
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	// loading in audio
	sf::SoundBuffer buffer;

	sf::Font font;

	if(!font.loadFromFile("content/dogicapixelbold.ttf")){
		std::cout << "Error loading font" << std::endl;
	}

	if(!playerTexture.loadFromFile("content/playerSprite.png")){
		// error
		return EXIT_FAILURE;
	}

    if(!buffer.loadFromFile("content/sound/mess_test2.ogg")){
		// error
		return EXIT_FAILURE;
	}

	// win condition
	sf::Text win;
	win.setFont(font);
	win.setString("You Win!");
	win.setCharacterSize(50);
	win.setPosition(460, 320);

	// lose condition
	sf::Text lose;
	lose.setFont(font);
	lose.setString("You Lose!");
	lose.setCharacterSize(50);
	lose.setPosition(460, 320);

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();

	playerTexture.setSmooth(true);
	playerTexture.setRepeated(false);
	playerSprite.setTexture(playerTexture);
	playerSprite.setScale(sf::Vector2f(float(screenWidth) / 5000, float(screenHeight) / 2500));
	playerSprite.setOrigin(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2);
	playerSprite.setPosition(screenWidth / 2, screenHeight / 2);

	//Bullets
	Bullet b1;
	std::vector<Bullet> bullets;

	// zombies
	sf::Texture zombieTexture;
	sf::Sprite zombieSprite;

	if(!zombieTexture.loadFromFile("content/zombieFace.png")){
		return EXIT_FAILURE;
	}

	zombieTexture.setSmooth(true);
	sf::Sprite zombie;
	zombieSprite.setTexture(zombieTexture);
	std::vector<sf::Sprite> zombies;

	//Vectors
	sf::Vector2f playerCenter;
	sf::Vector2f zombieCenter;
	sf::Vector2f aimZombDirNorm;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;

	while (window.isOpen()){
		while (window.pollEvent(event)){
			// when the window is closed, close the game
			if (event.type == sf::Event::Closed){
				window.close();
			}
			// when esc is pressed, close the game
			if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::Escape){
					window.close();
				}
			}
		}

		//Bint health = 50; // player health
		bool alive = true; // player alive

		sf::Texture background;
		background.loadFromFile("content/gamebg.png");

		// update
		playerCenter = sf::Vector2f(playerSprite.getPosition());
		mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
		aimDirNorm = mousePosWindow - playerCenter;

		float PI = 3.14159265f;
		float deg = atan2(aimDirNorm.y, aimDirNorm.x) * 180 / PI;
		playerSprite.setRotation(deg);

		//Player
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			playerSprite.move(-9.8f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			playerSprite.move(9.8f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			playerSprite.move(0.f, -9.8f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			playerSprite.move(0.f, 9.8f);
		}

		// player wrapping
		if (playerSprite.getPosition().x < 0){
			playerSprite.setPosition(screenWidth, playerSprite.getPosition().y);
		}
		if (playerSprite.getPosition().x > screenWidth){
			playerSprite.setPosition(0, playerSprite.getPosition().y);
		}
		if (playerSprite.getPosition().y < 0){
			playerSprite.setPosition(playerSprite.getPosition().x, screenHeight);
		}
		if (playerSprite.getPosition().y > screenHeight){
			playerSprite.setPosition(playerSprite.getPosition().x, 0);
		}

		// zombie spawning
		if(spawnCounter < 250){
			zombieSprite.setPosition(sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().x));
			zombieSprite.setScale(sf::Vector2f(float(screenWidth) / 12500, float(screenHeight) / 7500));
			zombies.push_back(zombieSprite);
			spawnCounter++;
		}

		// zombie following player
		for(size_t i = 0; i < zombies.size(); i++){
			sf::Sprite currentZombie = zombies[i];

			if(zombies[i].getPosition().x < playerSprite.getPosition().x){
				zombies[i].move(1.5f, 0.f);
			}
			if(zombies[i].getPosition().x > playerSprite.getPosition().x){
				zombies[i].move(-1.5f, 0.f);
			}
			if(zombies[i].getPosition().y < playerSprite.getPosition().y){
				zombies[i].move(0.f, 1.5f);
			}
			if(zombies[i].getPosition().y > playerSprite.getPosition().y){
				zombies[i].move(0.f, -1.5f);
			}

			// zombie rotation to face the player
			zombieCenter = sf::Vector2f(currentZombie.getPosition());
			aimZombDirNorm = playerCenter - zombieCenter;
			float zombieDeg = (atan2(aimZombDirNorm.y, aimZombDirNorm.x) * 180) / PI;
			currentZombie.setRotation(zombieDeg);
		}

		//Shooting
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			// shoot from player gun
			// b1.shape.setPosition(playerCenter);
			b1.shape.setPosition(playerSprite.getPosition());

			// normalize aim direction
			aimDir = mousePosWindow - playerCenter;
			aimDirNorm.x = aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
			aimDirNorm.y = aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));

			// set bullet velocity
			b1.currVelocity = aimDirNorm * b1.maxSpeed;

			// add bullet to vector
			bullets.push_back(Bullet(b1));

		}


		//Update Bullets
		for (size_t i = 0; i < bullets.size(); i++){
			bullets[i].shape.move(bullets[i].currVelocity);

			//Remove Bullets
			if (bullets[i].shape.getPosition().x < 0.f || bullets[i].shape.getPosition().x > window.getSize().x || bullets[i].shape.getPosition().y < 0.f || bullets[i].shape.getPosition().y > window.getSize().y){
				bullets.erase(bullets.begin() + i);
				i--;
			}

			if(bullets.size() > 100){
				bullets.erase(bullets.begin() + i);
				i--;
			}

			else{
				for(size_t k = 0; k < zombies.size(); k++){
					if(bullets[i].shape.getGlobalBounds().intersects(zombies[k].getGlobalBounds())){
						bullets.erase(bullets.begin() + i);
						zombies.erase(zombies.begin() + k);
					}
				}
			}
		}


		//Draw
		if(alive == true){
			window.clear();
			window.draw(sf::Sprite(background));

			for (size_t i = 0; i < zombies.size(); i++){
				window.draw(zombies[i]);
			}


			window.draw(playerSprite);

			// if # of zombies is 0, win scenario
			if (zombies.size() == 0){
				window.draw(win);
			}


			for (size_t i = 0; i < bullets.size(); i++){
				window.draw(bullets[i].shape);
			}
		}

		if(alive == false){
			window.clear();
			window.draw(sf::Sprite(background));

			window.draw(lose);
		}


		window.display();
	}


	// delocate memory


	return 0;
}
