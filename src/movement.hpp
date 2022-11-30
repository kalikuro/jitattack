// header file for movement
#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "constants.hpp"

class Movement: public sf::Drawable, public sf::Transformable{
	static const float maxSpeed;
	static const float acl;
	static const float rotationSpeed;

	public:
		Movement();
		~Movement();
		void moveSprite();
		void wrapSprite(sf::Sprite &sprite, sf::RenderWindow &window);
		void onMove(sf::Sprite &sprite);

	private:
		sf::Vector2f velocity;
		int mX;
		int mY;

		// float deltaTime();

};

