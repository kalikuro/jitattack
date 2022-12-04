// movement file

#include "movement.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

// initializing static const variables for movement purposes
const float Movement::acl = 9.8f;
const float Movement::rotationSpeed = 9.8f;

// movement will include a basic origin initialization
Movement::Movement(){
	velocity = sf::Vector2f(0, 0);
	mX = 0;
	mY = 0;

	// user = sf::Vector2f(0, 0);
}

Movement::~Movement(){}

// // moveSprite will be called in the main loop to move the sprite on the given event
void Movement::moveSprite(sf::Sprite &sprite){
	// when a certain movement happens the varibal will  be changes on the its coresponding axis position (x or y)
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		mX = -1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		mX = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		mY = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		mY = -1;
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		mX = 0;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		mY = 0;
	}

	// rotation of the sprite happens on facing of the x axis
	if(mX != 0){
		// simple multiplication of the rotation speed and the movement on the x axis will change the rotation of the sprite

		// we do mx * rotation speed because the value of mx will be the axis value on the 2d plane
		sprite.rotate(mX * rotationSpeed);
	}

	// movement on the y axis will be handled by the velocity (moving forward and backward [yet on this plane its up and down {y axis}]) of the sprite
	if(mY != 0){
		// the velocity will be changed by the acl (acceleration) and the movement on the y axis
		velocity.x += mY * acl * cos(sprite.getRotation() * (3.14159265359 / 180));
		velocity.y += mY * acl * sin(sprite.getRotation() * (3.14159265 / 180));

		// once the velocity is changed, the sprite will be moved by the velocity
		sprite.move(velocity);
	}



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