// shoot header file

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <vector>
#include "movement.hpp"

class Shoot{
	public:
		Shoot();
		~Shoot();

		void shootBullet(sf::Sprite &sprite, sf::RenderWindow &window);
		void updateBullets(sf::RenderWindow &window);
		void renderBullets(sf::RenderWindow &window);

	private:

		sf::Texture bulletTexture;
		sf::Sprite bulletSprite;

		sf::Vector2f playerCenter;
		sf::Vector2f mousePosWindow;
		sf::Vector2f aimDir;
		sf::Vector2f aimDirNorm;

		float angle;

		std::vector<sf::Sprite> bullets;

		sf::Clock clock;
		sf::Time time;

}