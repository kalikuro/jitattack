// movement header file

#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class Movement{
	public:
		sf::Vector2f playerCenter;
		sf::Vector2f mousePos;
		sf::Vector2f aimDir;
		float aimAngle;

		Movement();
		~Movement();

		void onMove(sf::Sprite &playerSprite, sf::Window &window);


};