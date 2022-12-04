#ifndef Zombie_H
#define Zombie_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class zombie
{
public:
	zombie();
	sf::Sprite& getSprite();
	void setLocation(float xpos, float ypos);
	void kill();
	bool isAlive();
	float getSpeed() const;
	void draw(sf::RenderWindow& window);

private:
	sf::Sprite zombieSprite;
	sf::Texture zombieTexture;
	bool alive;
	float speed;
};

#endif