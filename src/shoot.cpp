// shooting cpp file

#include "shoot.hpp"
#include <iostream>
#include <math.h>
#include "movement.hpp"


Shoot::Shoot(){
	shootX = 0;
	shootY = 0;
	shootVel = sf::Vector2f(0, 0);
}

Shoot::~Shoot(){}

void Shoot::onShoot(){


	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		// std::cout << "shoot" << std::endl;
		// std::cout << "shootX: " << shootX << std::endl;
		// std::cout << "shootY: " << shootY << std::endl;
		// std::cout << "shootVel.x: " << shootVel.x << std::endl;
		// std::cout << "shootVel.y: " << shootVel.y << std::endl;
		// std::cout << " " << std::endl;
	}
}
