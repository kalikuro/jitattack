#include "zombie.h"
#include <iostream>
#include <stdexcept>
#include <SFML/Graphics.hpp>
#include "Platform/Platform.hpp"

using namespace std;

int screenWidth = 1280;
int screenHeight = 720;

zombie::zombie(const int id, float sp){
	alive = true;
	speed = sp;

	if(!zombieTexture.loadFromFile("contents/zombie_sprite.png")){
		throw invalid_argument("Enemy not loaded!");
	}
	zombieSprite.setTexture(zombieTexture);
	zombieSprite.setScale(sf::Vector2f(float(screenWidth) / 3500, float(screenHeight) / 1750));
}

sf::Sprite & zombie::getSprite(){
	return zombieSprite;
}

void zombie::kill(){
	alive = false;
}

bool zombie::isAlive(){
	return alive;
}

void zombie::draw(sf::RenderWindow &win){
	zombieSprite.setTexture(zombieTexture);
	win.draw(zombieSprite);
}

float zombie::getSpeed() const{
	return speed;
}