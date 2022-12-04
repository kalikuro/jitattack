// // main file for game

// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
// #include <math.h>
// #include <vector>
// #include <time.h>
// #include <random>

// #include "Platform/Platform.hpp"
// #include "movement.hpp"
// #include "shoot.hpp"

// int main(void)
// {

// 	int screenWidth = 1280;
// 	int screenHeight = 720;

// 	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Jit Attack", sf::Style::Close | sf::Style::Titlebar);
// 	window.setFramerateLimit(60);
// 	sf::Event event;

// 	// loading in a sprite
// 	sf::Texture playerTexture;
// 	sf::Sprite playerSprite;

// 	// loading in a audio
// 	sf::SoundBuffer buffer;

// 	if (!playerTexture.loadFromFile("content/playerSprite.png"))
// 	{
// 		// error
// 		return EXIT_FAILURE;
// 	}

//     if (!buffer.loadFromFile("content/sound/mess_test2.ogg"))
// 	{
// 		// error
// 		return EXIT_FAILURE;
// 	}

// 	sf::Sound sound;
// 	sound.setBuffer(buffer);
// 	sound.play();

// 	playerTexture.setSmooth(true);
// 	playerTexture.setRepeated(false);
// 	playerSprite.setTexture(playerTexture);
// 	playerSprite.setScale(sf::Vector2f(float(screenWidth) / 5000, float(screenHeight) / 2500));
// 	playerSprite.setOrigin(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2);
// 	playerSprite.setPosition(screenWidth / 2, screenHeight / 2);

// 	while (window.isOpen()){

// 		while (window.pollEvent(event)){
// 			if (event.type == sf::Event::Closed)
// 				window.close();
// 		}

// 		sf::Texture background;
// 		background.loadFromFile("content/gamebg.png");

// 		window.clear();
// 		window.draw(sf::Sprite(background));
// 		window.draw(playerSprite);

// 		// movement
// 		Movement movement;
// 		movement.moveSprite(playerSprite);
// 		movement.wrapSprite(playerSprite, window);

// 		// shoot
// 		Shoot shoot;
// 		shoot.shootBullet(playerSprite, window);


// 		window.display();
// 	}

// 	return 0;
// }

#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"
#include<math.h>
#include<vector>
#include<cstdlib>

//LENGTH OF VECTOR: |V| = sqrt(V.x^2 + V.y^2)
//NORMALIZE VECTOR: U = V / |V|

using namespace sf;

class Bullet
{
public:
	CircleShape shape;
	Vector2f currVelocity;
	float maxSpeed;

	Bullet(float radius = 5.f)
		: currVelocity(0.f, 0.f), maxSpeed(15.f)
	{
		this->shape.setRadius(radius);
		this->shape.setFillColor(Color::Red);
	}
};

int main()
{
	srand(time(NULL));

	RenderWindow window(VideoMode(800, 600), "360 Shooter!", Style::Default);
	window.setFramerateLimit(60);

	//Player
	CircleShape player(25.f);
	player.setFillColor(Color::White);
	player.setPointCount(3);
	player.setOrigin(25.f, 25.f);

	//Bullets
	Bullet b1;
	std::vector<Bullet> bullets;

	//Enemy
	RectangleShape enemy;
	enemy.setFillColor(Color::Magenta);
	enemy.setSize(Vector2f(50.f, 50.f));
	// int spawnCounter = 20;

	std::vector<RectangleShape> enemies;

	//Vectors
	Vector2f playerCenter;
	Vector2f mousePosWindow;
	Vector2f aimDir;
	Vector2f aimDirNorm;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//Update
		//Vectors
		playerCenter = Vector2f(player.getPosition());
		mousePosWindow = Vector2f(Mouse::getPosition(window));
		aimDirNorm = mousePosWindow - playerCenter;

		float PI = 3.14159265f;
		float deg = atan2(aimDirNorm.y, aimDirNorm.x) * 180 / PI;
		player.setRotation(deg + 90);

		//Player
		if (Keyboard::isKeyPressed(Keyboard::A))
			player.move(-10.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::D))
			player.move(10.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::W))
			player.move(0.f, -10.f);
		if (Keyboard::isKeyPressed(Keyboard::S))
			player.move(0.f, 10.f);

		//Enemies
		// if (spawnCounter < 20)
		// 	spawnCounter++;

		// if(spawnCounter >= 20 && enemies.size() < 50)
		// {
		// 	enemy.setPosition(Vector2f(rand() % window.getSize().x, rand() % window.getSize().x));
		// 	enemies.push_back(RectangleShape(enemy));

		// 	spawnCounter = 0;
		// }

		//Shooting
		if(Mouse::isButtonPressed(Mouse::Left)){
			b1.shape.setPosition(playerCenter);
			b1.currVelocity = aimDirNorm;
			bullets.push_back(Bullet(b1));
		}

		//Update Bullets
		for (size_t i = 0; i < bullets.size(); i++)
		{
			bullets[i].shape.move(bullets[i].currVelocity);

			//Remove Bullets
			if (bullets[i].shape.getPosition().x < 0.f || bullets[i].shape.getPosition().x > window.getSize().x
				|| bullets[i].shape.getPosition().y < 0.f || bullets[i].shape.getPosition().y > window.getSize().y)
			{
				bullets.erase(bullets.begin() + i);
				i--;
			}
		}

		//Draw
		window.clear();

		// for (size_t i = 0; i < enemies.size(); i++)
		// {
		// 	window.draw(enemies[i]);
		// }

		window.draw(player);

		for (size_t i = 0; i < bullets.size(); i++)
		{
			window.draw(bullets[i].shape);
		}

		window.display();
	}

	return 0;
}