// add movement for the sprite

// #include "movement.hpp"
// #include <iostream>

// const float Movement::maxSpeed = 0.5f;
// const float Movement::acl = 1.0f;
// const float Movement::rotationSpeed = 0.5f;



// Movement::Movement(){
// 	velocity = sf::Vector2f(0, 0);
// 	mX = 0;
// 	mY = 0;
// }

// Movement::~Movement(){}

// void Movement::moveSprite(){
// 	// std::cout << "moveSprite" << std::endl;
// 	// std::cout << "mX: " << mX << std::endl;
// 	// std::cout << "mY: " << mY << std::endl;
// 	// std::cout << "velocity.x: " << velocity.x << std::endl;
// 	// std::cout << "velocity.y: " << velocity.y << std::endl;

// 	if(mX == 1){
// 		velocity.x += acl;
// 	}
// 	if(mX == -1){
// 		velocity.x -= acl;
// 	}
// 	if(mY == 1){
// 		velocity.y += acl;
// 	}
// 	if(mY == -1){
// 		velocity.y -= acl;
// 	}

// 	if(velocity.x > maxSpeed){
// 		velocity.x = maxSpeed;
// 	}
// 	if(velocity.x < -maxSpeed){
// 		velocity.x = -maxSpeed;
// 	}
// 	if(velocity.y > maxSpeed){
// 		velocity.y = maxSpeed;
// 	}
// 	if(velocity.y < -maxSpeed){
// 		velocity.y = -maxSpeed;
// 	}

// 	// std::cout << "velocity.x: " << velocity.x << std::endl;
// 	// std::cout << "velocity.y: " << velocity.y << std::endl;
// 	// std::cout << " " << std::endl;
// }

// void Movement::wrapSprite(sf::Sprite &sprite, sf::RenderWindow &window){
// 	// std::cout << "wrapSprite" << std::endl;
// 	// std::cout << "sprite.getPosition().x: " << sprite.getPosition().x << std::endl;
// 	// std::cout << "sprite.getPosition().y: " << sprite.getPosition().y << std::endl;
// 	// std::cout << "sprite.getGlobalBounds().width: " << sprite.getGlobalBounds().width << std::endl;
// 	// std::cout << "sprite.getGlobalBounds().height: " << sprite.getGlobalBounds().height << std::endl;
// 	// std::cout << " " << std::endl;

// 	if(sprite.getPosition().x > window.getSize().x){
// 		sprite.setPosition(0, sprite.getPosition().y);
// 	}
// 	if(sprite.getPosition().x < 0){
// 		sprite.setPosition(window.getSize().x, sprite.getPosition().y);
// 	}
// 	if(sprite.getPosition().y > window.getSize().y){
// 		sprite.setPosition(sprite.getPosition().x, 0);
// 	}
// 	if(sprite.getPosition().y < 0){
// 		sprite.setPosition(sprite.getPosition().x, window.getSize().y);
// 	}
// }

// void Movement::onMove(sf::Sprite &sprite){

// 	sprite.move(velocity);
// }

// class Movement{
// 	static const float maxSpeed;
// 	static const float acl;
// 	static const float rotationSpeed;

// 	public:
// 		Movement();
// 		~Movement();
// 		void moveSprite();
// 		void wrapSprite(sf::Sprite &sprite, sf::RenderWindow &window);
// 		void onMove(sf::Sprite &sprite);

// 	private:
// 		sf::Vector2f velocity;
// 		int mX;
// 		int mY;

// };

// const float Movement::maxSpeed = 0.5f;
// const float Movement::acl = 1.0f;
// const float Movement::rotationSpeed = 0.5f;

// Movement::Movement(){
// 	velocity = sf::Vector2f(0, 0);
// 	mX = 0;
// 	mY = 0;
// }

// Movement::~Movement(){}

// void Movement::moveSprite(){
// 	// std::cout << "moveSprite" << std::endl;
// 	// std::cout << "mX: " << mX << std::endl;
// 	// std::cout << "mY: " << mY << std::endl;
// 	// std::cout << "velocity.x: " << velocity.x << std::endl;
// 	// std::cout << "velocity.y: " << velocity.y << std::endl;

// 	if(mX == 1){
// 		velocity.x += acl;
// 	}
// 	if(mX == -1){
// 		velocity.x -= acl;
// 	}
// 	if(mY == 1){
// 		velocity.y += acl;
// 	}
// 	if(mY == -1){
// 		velocity.y -= acl;
// 	}

// 	if(velocity.x > maxSpeed){
// 		velocity.x = maxSpeed;
// 	}
// 	if(velocity.x < -maxSpeed){
// 		velocity.x = -maxSpeed;
// 	}
// 	if(velocity.y > maxSpeed){
// 		velocity.y = maxSpeed;
// 	}
// 	if(velocity.y < -maxSpeed){
// 		velocity.y = -maxSpeed;
// 	}

// 	// std::cout << "velocity.x: " << velocity.x << std::endl;
// 	// std::cout << "velocity.y: " << velocity.y << std::endl;
// 	// std::cout << " " << std::endl;
// }

// void Movement::wrapSprite(sf::Sprite &sprite, sf::RenderWindow &window){
// 	// std::cout << "wrapSprite" << std::endl;
// 	// std::cout << "sprite.getPosition().x: " << sprite.getPosition().x << std::endl;
// 	// std::cout << "sprite.getPosition().y: " << sprite.getPosition().y << std::endl;
// 	// std::cout << "sprite.getGlobalBounds().width: " << sprite.getGlobalBounds().width << std::endl;
// 	// std::cout << "sprite.getGlobalBounds().height: " << sprite.getGlobalBounds().height << std::endl;
// 	// std::cout << " " << std::endl;

// 	if(sprite.getPosition().x > window.getSize().x){
// 		sprite.setPosition(0, sprite.getPosition().y);
// 	}
// 	if(sprite.getPosition().x < 0){
// 		sprite.setPosition(window.getSize().x, sprite.getPosition().y);
// 	}
// 	if(sprite.getPosition().y > window.getSize().y){
// 		sprite.setPosition(sprite.getPosition().x, 0);
// 	}
// 	if(sprite.getPosition().y < 0){
// 		sprite.setPosition(sprite.getPosition().x, window.getSize().y);
// 	}
// }

// void Movement::onMove(sf::Sprite &sprite){

// 	sprite.move(velocity);
// }

#include "movement.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

// initializing static const variables for movement purposes
const float Movement::maxSpeed = 0.1f;
const float Movement::acl = 0.1f;
const float Movement::rotationSpeed = 0.1f;

// movement will include a basic origin initialization
Movement::Movement(){
	velocity = sf::Vector2f(0, 0);
	mX = 0;
	mY = 0;
}

Movement::~Movement(){}

// moveSprite will be called in the main loop to move the sprite on the given event
void Movement::moveSprite(sf::Sprite &sprite){
	// if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
	// 	sprite.move(-1, 0);
	// }
	// if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
	// 	sprite.move(1, 0);
	// }
	// if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
	// 	sprite.move(0, -1);
	// }
	// if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
	// 	sprite.move(0, 1);
	// }

	// if(mX == 1){
	// 	velocity.x += acl;
	// }
	// if(mX == -1){
	// 	velocity.x -= acl;
	// }
	// if(mY == 1){
	// 	velocity.y += acl;
	// }
	// if(mY == -1){
	// 	velocity.y -= acl;
	// }

	// if(velocity.x > maxSpeed){
	// 	velocity.x = maxSpeed;
	// }
	// if(velocity.x < -maxSpeed){
	// 	velocity.x = -maxSpeed;
	// }
	// if(velocity.y > maxSpeed){
	// 	velocity.y = maxSpeed;
	// }
	// if(velocity.y < -maxSpeed){
	// 	velocity.y = -maxSpeed;
	// }

	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
	// 	sprite.rotate(-rotationSpeed);
	// }
	// if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
	// 	sprite.rotate(rotationSpeed);
	// }

	// mX = 0;
	// mY = 0;

	// if(mX != 0){
	// 	sprite.rotate(mX * rotationSpeed);
	// }

	// if(mY != 0){

	// }

	// if(velocity.x > maxSpeed){
	// 	velocity.x = maxSpeed;
	// }
	// if(velocity.x < -maxSpeed){
	// 	velocity.x = -maxSpeed;
	// }
	// if(velocity.y > maxSpeed){
	// 	velocity.y = maxSpeed;
	// }
	// if(velocity.y < -maxSpeed){
	// 	velocity.y = -maxSpeed;
	// }

	// if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){

	// }

	// while event is being handled, the movement will be handled
	// when a certain movement happens the varibal will  be changes on the its coresponding axis position (x or y)
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		mX = -1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		mX = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		mY = 1;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		mY = -1;
	}

	// rotation of the sprite happens on facing of the x axis
	if(mX != 0){
		// simple multiplication of the rotation speed and the movement on the x axis will change the rotation of the sprite

		// we do mx * rotation speed because the value of mx will be the axis value on the 2d plane
		sprite.rotate(mX * rotationSpeed);
	}

	// movement on the y axis will be handled by the velocity (moving forward and backward [yet on this plane its up and down {y axis}]) of the sprite
	if(mY != 0){
		// the velocity will be changed by the acl (acceleration) and the movement on the y axis
		velocity.x += mY * acl * cos(sprite.getRotation() * (3.14159265359 / 180));
		velocity.y += mY * acl * sin(sprite.getRotation() * (3.14159265 / 180));

		// once the velocity is changed, the sprite will be moved by the velocity
		sprite.move(velocity);
	}


}

// window wrapping in this instance is similair to bounding the playing field for the game
void Movement::wrapSprite(sf::Sprite &sprite, sf::RenderWindow &window){
	if(sprite.getPosition().x > window.getSize().x){
		sprite.setPosition(0, sprite.getPosition().y);
	}
	if(sprite.getPosition().x < 0){
		sprite.setPosition(window.getSize().x, sprite.getPosition().y);
	}
	if(sprite.getPosition().y > window.getSize().y){
		sprite.setPosition(sprite.getPosition().x, 0);
	}
	if(sprite.getPosition().y < 0){
		sprite.setPosition(sprite.getPosition().x, window.getSize().y);
	}
}