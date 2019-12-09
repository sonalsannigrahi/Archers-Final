#include "Player.hpp"

Player::Player(){
    sf::Texture* texture = new sf::Texture();
    texture -> loadFromFile("Character/Assets/charac_arm.png");
    sprite -> setTexture(*texture);
    sf::Texture* texturem = new sf::Texture();
    texturem -> loadFromFile("Character/Assets/hand_p.png");
    spritem -> setTexture(*texturem);
}

void Player::setWindow(sf::RenderWindow* gameWindow){
    window = gameWindow;
}

void Player::setSize(int width, int height ){
    playerWidth = width;
    playerHeight = height;
}

void Player::setGround(Ground* ground){
    ground_p = ground;
    id = ground_p.createGround(0);
    ground_p.setGoundPosition(id, sprite -> getPosition().x, sprite -> getPosition().y);

}

void Player::updateFrame(double time){
    // need to test implementation
    sf::Vector2i mousePosition;
    float angle;
    sf::Vector2f playerPosition;
    sf::Vector2i windowPosition;
    double a, b;    

    spritem -> setOrigin(sprite -> getOrigin().x,sprite -> getOrigin().y);
    spritem -> setPosition(sprite -> getPosition().x + windowPosition.x/10, sprite -> getPosition().y - windowPosition/4);

    playerPosition = spritem -> getPosition();
    spritem -> setRotation(0);
    sf::Event Event;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        mousePosition = sf::Mouse::getPosition();
        windowPosition = window -> getPosition();
        a = mousePosition.x - windowPosition.x - playerPosition.x;
        b = mousePosition.y - windowPosition.y - playerPosition.y;
        angle = (-atan2( a , b) * 180 + 180) /  3.14159265359;
        spritem -> setRotation(angle);
    }

    window -> draw(*sprite);
    window -> draw(*spritem);
}

