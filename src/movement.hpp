// header file for movement
#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>

// insintal class for needed instances of movement
class Movement{

	public:
		// sf::Vector2f user

		sf::Vector2f velocity;
		static const float rotationSpeed;
		static const float acl;
		float mY;
		float mX;

		Movement();
		~Movement();
		void moveSprite(sf::Sprite &sprite);
		void wrapSprite(sf::Sprite &sprite, sf::RenderWindow &window);

	// private:
};

