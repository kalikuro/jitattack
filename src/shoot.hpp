// shooting header file for necassary instances of shooting

#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "movement.hpp"

// insintal class for needed instances of shooting
class Shoot{
	Movement movement;
	public:

		Shoot();
		~Shoot();

		void onShoot(sf::Sprite &sprite, sf::RenderWindow &window);

		float shootX = movement.velocity.x;
		float shootY = movement.velocity.y;
		sf::Vector2f shootVel = movement.velocity;
};