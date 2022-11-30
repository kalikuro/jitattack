// header file for movement
#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "constants.hpp"

class Movement{
	public:
		Movement();
		~Movement();
		void moveSprite(sf::Sprite &sprite);
		void wrapSprite(sf::Sprite &sprite, sf::RenderWindow &window);


};

