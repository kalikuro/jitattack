// movement file

#include "Movement.hpp"

Movement::Movement(){
}

Movement::~Movement(){
}

void Movement::onMove(sf::Sprite &playerSprite, sf::Window &window){
	playerCenter = sf::Vector2f(playerSprite.getPosition());
	mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
	aimDir = mousePos - playerCenter;

	aimAngle = atan2(aimDir.y, aimDir.x) * 180 / 3.14159265;
	playerSprite.setRotation(aimAngle);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		playerSprite.move(-9.8f, 0.f);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		playerSprite.move(9.8f, 0.f);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		playerSprite.move(0.f, -9.8f);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		playerSprite.move(0.f, 9.8f);
	}

	// player wrapping
	if(playerSprite.getPosition().x < 0){
		playerSprite.setPosition(window.getSize().x, playerSprite.getPosition().y);
	}
	if(playerSprite.getPosition().x > window.getSize().x){
		playerSprite.setPosition(0, playerSprite.getPosition().y);
	}
	if(playerSprite.getPosition().y < 0){
		playerSprite.setPosition(playerSprite.getPosition().x, window.getSize().y);
	}
	if(playerSprite.getPosition().y > window.getSize().y){
		playerSprite.setPosition(playerSprite.getPosition().x, 0);
	}
}