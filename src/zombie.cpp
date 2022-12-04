#include "zombie.h"
#include <iostream>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "Platform/Platform.hpp"

using namespace std;

int screenWidth = 1280;
int screenHeight = 720;


zombie::zombie(){
	alive = true;
	speed = 9.8f;

	if(!zombieTexture.loadFromFile("content/zombie_sprite.png")){
		cout << "Error loading zombie sprite" << endl;
	}
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setScale(sf::Vector2f(float(screenWidth) / 3500, float(screenHeight) / 1750));

}

sf::Sprite & zombie::getSprite(){
	return zombieSprite;
}

void zombie::setLocation(float xpos, float ypos){
	zombieSprite.setPosition(xpos, ypos);
}

void zombie::kill(){
	alive = false;
}

bool zombie::isAlive(){
	return alive;
}

void zombie::draw(sf::RenderWindow &window){
	zombieSprite.setTexture(zombieTexture);
	window.draw(zombieSprite);
}

float zombie::getSpeed() const{
	return speed;
}