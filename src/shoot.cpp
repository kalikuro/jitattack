// shoot cpp file

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <vector>
#include "movement.hpp"
#include "shoot.hpp"

Movement movement;
Shoot s;
std::vector<Shoot> bullets;

Shoot::Shoot(){
	radius = 5.f;
	speed = 10.f;
	velocity = sf::Vector2f(1.f, 1.f);
	circle.setRadius(radius);
}

Shoot::~Shoot(){}

void Shoot::shootBullet(sf::Sprite &sprite, sf::RenderWindow &window){
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		bullets.push_back(Shoot());
		bullets.back().circle.setPosition(sprite.getPosition());
		bullets.back().velocity = movement.aimDir;

	}

	for(size_t i = 0; i < bullets.size(); i++){
		bullets[i].circle.move(bullets[i].velocity);
	}

	for(size_t i = 0; i < bullets.size(); i++){
		window.draw(bullets[i].circle);
	}


}