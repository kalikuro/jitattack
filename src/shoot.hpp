// shoot header file

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <vector>
#include "movement.hpp"

class Shoot{
	public:
		Shoot();
		~Shoot();

		void shootBullet(sf::Sprite &sprite, sf::RenderWindow &window);

		float radius;
		float speed;
		sf::Vector2f velocity;
		sf::CircleShape circle;
};