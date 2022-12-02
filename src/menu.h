// funny menu header シ
#pragma once

#include <SFML/Graphics.hpp>

#define max_num_of_items 2

class Menu{
	int selectedItemIndex;
	sf::Font font;
	sf::Text text[max_num_of_items];
	public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem(){
		return selectedItemIndex;
	}

};