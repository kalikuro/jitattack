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

const float Movement::maxSpeed = 0.1f;
const float Movement::acl = 0.1f;
const float Movement::rotationSpeed = 0.1f;


Movement::Movement(){
	velocity = sf::Vector2f(0, 0);
	mX = 0;
	mY = 0;
}

Movement::~Movement(){}

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

	mX = 0;
	mY = 0;

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

	if(mX != 0){
		sprite.rotate(mX * rotationSpeed);
	}

	if(mY != 0){
		velocity.x += mY * acl * cos(sprite.getRotation() * 3.14159265 / 180);
		velocity.y += mY * acl * sin(sprite.getRotation() * 3.14159265 / 180);
	}
	sprite.move(velocity);
}

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