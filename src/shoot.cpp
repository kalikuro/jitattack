// shooting cpp file

#include <math.h>
#include <SFML/Graphics.hpp>
#include "shoot.hpp"
#include "movement.hpp"

std::vector<Shoot> bullets;

Shoot::Shoot(){
	float circleRadius = 5.f;
	sf::Vector2f shootVel(0.f, 0.f);
	speed = 0.1f;


}

Shoot::~Shoot(){
}

void onShoot(sf::Sprite &sprite, sf::RenderWindow &window){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){


	}
}

