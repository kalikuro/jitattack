// shooting cpp file

#include "shoot.hpp"
#include <iostream>
#include <math.h>
#include "movement.hpp"
#include <SFML/Graphics.hpp>

Shoot::Shoot(){
	if(movement.velocity.x > 0){
		shootX = movement.velocity.x + 1;
	}

	if(movement.velocity.x < 0){
		shootX = movement.velocity.x - 1;
	}

}

Shoot::~Shoot(){}

void Shoot::onShoot(sf::Sprite &sprite, sf::RenderWindow &window){

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		// sprite.setPosition(sprite.getPosition().x + shootX, sprite.getPosition().y + shootY);

		// sf::CircleShape circle(5);
		// circle.setFillColor(sf::Color::Red);
		// circle.setPosition(sprite.getPosition().x + shootX, sprite.getPosition().y + shootY);

		// window.draw(circle);

		// for(int i = 0; i < 100; i++){
		// 	circle.setPosition(circle.getPosition().x + shootX + i, circle.getPosition().y + shootY + i);
		// 	window.draw(circle);
		// }

		sf::CircleShape circle(5);
		circle.setFillColor(sf::Color::Red);
		circle.setPosition(sprite.getPosition().x + shootX, sprite.getPosition().y + shootY);

		for(int i = 0; i < 100; i++){
			// circle.move(shootX, shootY);
			circle.move(shootVel);

			window.draw(circle);
		}

	}
}
