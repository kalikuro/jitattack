
#include "movement.hpp"
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

// movement will include a basic origin initialization
Movement::Movement(){

}

Movement::~Movement(){}

// moveSprite will be called in the main loop to move the sprite on the given event
void Movement::moveSprite(sf::Sprite &sprite){

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		sprite.move(-5.f, 0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		sprite.move(5.f, 0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		sprite.move(0, -5.f);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		sprite.move(0, 1.f);
	}

	playerCenter = sf::Vector2f(sprite.getPosition());
	mousePosWindow = sf::Vector2f(sf::Mouse::getPosition());
	aimDir = mousePosWindow - playerCenter;

	angle = (atan2f(aimDir.y, aimDir.x)) * 180 / 3.14159265;
	std::cout << angle << std::endl;

	sprite.setRotation(angle + 270);


}

// window wrapping in this instance is similair to bounding the playing field for the game
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