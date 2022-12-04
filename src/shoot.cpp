// shooting cpp file

#include <math.h>
#include <SFML/Graphics.hpp>
#include "shoot.hpp"
#include "movement.hpp"

Shoot::Shoot(){
	bullet.setRadius(circleRadius);
	bullet.setFillColor(sf::Color::Red);
	bullet.setOrigin(circleRadius, circleRadius);
}

Shoot::~Shoot(){}

void Shoot::onShoot(sf::Sprite &sprite, sf::RenderWindow &window){
	// get the mouse position
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	// get the player position
	playerPos = sprite.getPosition();
	// get the direction of the mouse
	aimDirection = mousePos - playerPos;
	// normalize the direction
	aimDirection = aimDirection / sqrt(pow(aimDirection.x, 2) + pow(aimDirection.y, 2));
	// set the velocity
	shootVel = aimDirection * speed;
	// set the bullet position
	bullet.setPosition(playerPos);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		bullet.move(shootVel);
	}
}

