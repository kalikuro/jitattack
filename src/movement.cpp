// add movement for the sprite

#include "movement.hpp"
#include <iostream>

Movement::Movement(){

}

Movement::~Movement(){

}

void Movement::moveSprite(sf::Sprite &sprite, sf::RenderWindow &window){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		sprite.move(0, -1);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		sprite.move(0, 1);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		sprite.move(-1, 0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		sprite.move(1, 0);
	}
}

void Movement::wrapSprite(sf::Sprite &sprite, sf::RenderWindow &window){
	if(sprite.getPosition().x > window.getSize().x){
		sprite.setPosition(0, sprite.getPosition().y);
	}
	if(sprite.getPosition().x < 0){
		sprite.setPosition(window.getSize().x, sprite.getPosition().y);
	}
	if(sprite.getPosition().y > window.getSize().y){
		sprite.setPosition(sprite.getPosition().x, 0);
	}
	if(sprite.getPosition().y < 0){
		sprite.setPosition(sprite.getPosition().x, window.getSize().y);
	}
}
