// header file for movement
#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "constants.hpp"

class Movement{

	public:
		static const float maxSpeed;
		static const float rotationSpeed;
		static const float acl;

		Movement();
		~Movement();
		void moveSprite(sf::Sprite &sprite);
		void wrapSprite(sf::Sprite &sprite, sf::RenderWindow &window);

	private:
		sf::Vector2f velocity;
		float mX;
		float mY;
};

