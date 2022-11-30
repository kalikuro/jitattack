// shooting header file for necessary instances of shooting

#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "movement.hpp"

// insintal class for needed instances of shooting
class Shoot{

	public:

		Shoot();
		~Shoot();

		void onShoot();

		float shootX;
		float shootY;
		sf::Vector2f shootVel;

};