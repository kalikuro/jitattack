// header file for movement
#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

// insintal class for needed instances of movement
class Movement{

	public:
		// sf::Vector2f user

		// static const float maxSpeed;
		// static const float rotationSpeed;
		// static const float acl;

		Movement();
		~Movement();
		void moveSprite(sf::Sprite &sprite);
		void wrapSprite(sf::Sprite &sprite, sf::RenderWindow &window);

	// private:
		// sf::Vector2f velocity;
		// float mY;
		// float mX;
};

