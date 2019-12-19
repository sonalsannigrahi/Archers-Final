#include "player.hpp"
#include <iostream>

Player::Player(){
	sf::Texture* texture = new sf::Texture();
	texture -> loadFromFile("Character/charac_arm.png");
	sprite -> setTexture(*texture);
	sf::Texture* texturem = new sf::Texture();
	texturem -> loadFromFile("Character/hand_p.png");
	spritem -> setTexture(*texturem);
}

void Player::setWindow(sf::RenderWindow* gameWindow){
	window = gameWindow;
}

void Player::setSize(int width, int height ){
	playerWidth = width;
	playerHeight = height;
}

void Player::updateFrame(double time){
	// need to test implementation
    sf::Vector2i mousePosition;
    float angle;
    sf::Vector2f playerPosition;
    sf::Vector2i windowPosition;
    sf::Vector2u windowSize;
    double a, b;	

    windowSize = window -> getSize();
    sprite -> setScale(0.5f, 0.5f);
    spritem -> setScale(0.5f,0.5f); 
    spritem -> setOrigin(-float(windowSize.x) * 0.125 + sprite -> getOrigin().x,sprite -> getOrigin().y -float(windowSize.x) * 0.08);
    
    spritem -> setPosition(sprite -> getPosition().x ,sprite -> getPosition().y);
    playerPosition = spritem -> getPosition();
    spritem -> setRotation(0);
    sf::Event Event;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        mousePosition = sf::Mouse::getPosition();
        windowPosition = window -> getPosition();
    	a = mousePosition.x - windowPosition.x - playerPosition.x;
        b = mousePosition.y - windowPosition.y - playerPosition.y;
        angle = -(-atan2( a , b) * 180 + 180) /  3.14159265359;
        spritem -> setRotation(angle);
    }

    window -> draw(*sprite);
    window -> draw(*spritem);
}
