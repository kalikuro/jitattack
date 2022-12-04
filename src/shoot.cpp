// shoot cpp file

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <vector>
#include "movement.hpp"
#include "shoot.hpp"

Shoot::Shoot(){
	bulletTexture.loadFromFile("content/bulletSprite.png");
	bulletTexture.setSmooth(true);
	bulletTexture.setRepeated(false);
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setScale(sf::Vector2f(float(screenWidth) / 5000, float(screenHeight) / 2500));
	bulletSprite.setOrigin(bulletTexture.getSize().x / 2, bulletTexture.getSize().y / 2);
}

Shoot::~Shoot(){
}

void Shoot::shootBullet(sf::Sprite &sprite, sf::RenderWindow &window){
	playerCenter = sf::Vector2f(sprite.getPosition().x + sprite.getGlobalBounds().width / 2, sprite.getPosition().y + sprite.getGlobalBounds().height / 2);
	mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
	aimDir = sf::Vector2f(mousePosWindow.x - playerCenter.x, mousePosWindow.y - playerCenter.y);
	aimDirNorm = sf::Vector2f(aimDir.x / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)), aimDir.y / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
	angle = atan2(aimDirNorm.y, aimDirNorm.x) * 180 / 3.14159265;
	bulletSprite.setPosition(playerCenter);
	bulletSprite.setRotation(angle);
	bullets.push_back(bulletSprite);
}

void Shoot::updateBullets(sf::RenderWindow &window){
	for (int i = 0; i < bullets.size(); i++){
		bullets[i].move(aimDirNorm.x * 10, aimDirNorm.y * 10);
		if (bullets[i].getPosition().x > window.getSize().x || bullets[i].getPosition().x < 0 || bullets[i].getPosition().y > window.getSize().y || bullets[i].getPosition().y < 0){
			bullets.erase(bullets.begin() + i);
		}
	}
}


void Shoot::renderBullets(sf::RenderWindow &window){
	for (int i = 0; i < bullets.size(); i++){
		window.draw(bullets[i]);
	}
}


