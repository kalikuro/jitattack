// shooting cpp file

#include <math.h>
#include <SFML/Graphics.hpp>
#include "shoot.hpp"
#include "movement.hpp"

Shoot::Shoot(){
	float circleRadius = 5.f;
	sf::Vector2f shootVel(0.f, 0.f);
	speed = 0.1f;
}

Shoot::~Shoot(){
}

