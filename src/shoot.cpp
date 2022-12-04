// shooting cpp file

#include <math.h>
#include <SFML/Graphics.hpp>
#include "shoot.hpp"
#include "movement.hpp"

std::vector<Shoot> bullets;
const float circleRadius = 5.f;

Shoot::Shoot(){
	shootVel = sf::Vector2f(0.f, 0.f);
	speed = 0.1f;

}

Shoot::~Shoot(){
}

void Shoot::onShoot(sf::Sprite &sprite, sf::RenderWindow &window){
	playerPos = Vector2f(sprite.getPosition().x, sprite.getPosition().y);
	aimDirection = shootVel / sqrt(pow(shootVel.x, 2) + pow(shootVel.y, 2));

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		bullet.shape.setPositon(playerPos);
		bullet.shootVel = aimDirection * speed;
		bullets.push_back(bullet);
	}

	for(int i = 0; i < bullets.size(); i++){
		bullets[i].shape.move(bullets[i].shootVel);
		window.draw(bullets[i].shape);
	}


}
