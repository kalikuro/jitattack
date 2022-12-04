// shooting header file for necassary instances of shooting

#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

// insintal class for needed instances of shooting
class Shoot{

	public:
		static const float circleRadius;
		static const float speed;
		sf::Vector2f shootVel;
		sf::Vector2f<float> aimDirection;
		sf::Vector2f<float> playerPos;
		sf::CircleShape bullet;

		Shoot();
		~Shoot();

		void onShoot(sf::Sprite &sprite, sf::RenderWindow &window);

};