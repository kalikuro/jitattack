#ifndef Zombie_H
#define Zombie_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class zombie{
	public:
		zombie(){};
		zombie(const int, float);
		sf:: Sprite & getSprite();
		void selectLocation(float, float);
		void kill();
		bool isAlive();
		float getSpeed() const;
		void draw(sf::RenderWindow & win);

	private:
		sf::Sprite zombieSprite;
		sf::Texture zombieTexture;
		bool alive;
		float speed;
};

#endif