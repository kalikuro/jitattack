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
	velocity = sf::Vector2f(0, 0);
	circle.setRadius(radius);
}

Shoot::~Shoot(){}

void Shoot::shootBullet(sf::Sprite &sprite, sf::RenderWindow &window){
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		s.circle.setPosition(sprite.getPosition());
		velocity = movement.aimDir * speed;
		bullets.push_back(s);
	}

	for(size_t i = 0; i < bullets.size(); i++){
		bullets[i].circle.move(bullets[i].velocity);
		if(bullets[i].circle.getPosition().x > window.getSize().x){
			bullets.erase(bullets.begin() + i);
		}
		if(bullets[i].circle.getPosition().x < 0){
			bullets.erase(bullets.begin() + i);
		}
		if(bullets[i].circle.getPosition().y > window.getSize().y){
			bullets.erase(bullets.begin() + i);
		}
		if(bullets[i].circle.getPosition().y < 0){
			bullets.erase(bullets.begin() + i);
		}

		window.draw(bullets[i].circle);
	}

}