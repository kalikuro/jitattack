// main menu file シ

#include "menu.h"

Menu::Menu(float width, float height){
	if(!font.loadFromFile("content/dogicapixelbold.ttf")){
		std::cout << "no hay font" << std::endl;
	}

	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Yellow);
	text[0].setString("Start");
	text[0].setPosition(sf::Vector2f(width / 2, height / (max_num_of_items + 1) * 1));

	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString("How to Play");
	text[1].setPosition(sf::Vector2f(width / 2, height / (max_num_of_items + 1) * 2));

	selectedItemIndex = 0;
}

Menu::~Menu(){

}

void Menu::draw(sf::RenderWindow &window){
	for(int i = 0; i < max_num_of_items; i++){
		window.draw(text[i]);
	}
}

void Menu::MoveUp(){
	if(selectedItemIndex - 1 >= 0){
		text[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		text[selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}

void Menu::MoveDown(){
	if(selectedItemIndex + 1 < max_num_of_items){
		text[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		text[selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}