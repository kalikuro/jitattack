// shooting cpp file

#include <math.h>
#include <SFML/Graphics.hpp>
#include "shoot.hpp"
#include "movement.hpp"

Shoot b;
std::vector<Shoot> bullets;
const float circleRadius = 5.f;
const float speed = 0.1f;

Shoot::Shoot(){
	shootVel = sf::Vector2f(0.f, 0.f);
}

Shoot::~Shoot(){
}

void Shoot::onShoot(sf::Sprite &sprite, sf::RenderWindow &window){
	playerPos = sprite.getPosition();
	aimDirection = shootVel/sqrt(pow(shootVel.x, 2) + pow(shootVel.y, 2));

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		bullets.push_back(Shoot());
		bullets.back().shootVel = aimDirection;
		bullets.back().shootVel.x *= speed;
		bullets.back().shootVel.y *= speed;
	}

	for(int i = 0; i < bullets.size(); i++){

	}


}
