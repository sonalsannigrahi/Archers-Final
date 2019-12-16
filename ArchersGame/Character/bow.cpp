#include "bow.hpp"
#include <iostream>

Player::Player(){

	sf::Texture* texture = new sf::Texture();
	texture -> loadFromFile("Character/charac_arm.png");
	sprite -> setTexture(*texture);
	sf::Texture* texturem = new sf::Texture();
	texturem -> loadFromFile("Character/hand_p.png");
	spritem -> setTexture(*texturem);
    //characterSprites.push_back(*spritem);//
    //sf::Texture* texturee = new sf::Texture();
    /*texturee -> loadFromFile("Character/endless.png");
    spritee -> setTexture(*texturee);
    characterSprites.push_back(*spritee);
    sf::Texture* texturec = new sf::Texture();
    texturec -> loadFromFile("Character/campaign.png");
    spritec -> setTexture(*texturec);
    characterSprites.push_back(*spritec);
    //sf::Texture* textureo = new sf::Texture();
    //textureo -> loadFromFile("opening.png");
    //opening -> setTexture(*textureo);
    //characterSprites.push_back(*opening);*/
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
    sf::FloatRect spriteSize;
    sf::FloatRect spriteSiz;
    double a, b;	

    windowSize = window -> getSize();
    sprite -> setScale(0.4f, 0.4f);
    spriteSize = spritem -> getGlobalBounds();
    spriteSiz = sprite -> getGlobalBounds();
    sprite -> setPosition(float(windowSize.x) * 0.08, float(windowSize.y) * 0.125); //
    spritem -> setScale(0.5f,0.5f); 
    spritem -> setOrigin(float(spriteSize.width)/2,float(spriteSize.height)/2);
    
    spritem -> setPosition(sprite -> getPosition().x + float(spriteSiz.width)/1.8  ,sprite -> getPosition().y + float(spriteSiz.height)/4);
    playerPosition = spritem -> getPosition();
    spritem -> setRotation(0);

    sf::Event Event;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){

        mousePosition = sf::Mouse::getPosition();
        windowPosition = window -> getPosition();
    	a = mousePosition.x;
        b = mousePosition.y;
        angle = -(-atan2( a , b) * 180 + 180)/3.14159265359;
        if (angle < 0){
            spritem -> setRotation(angle);
        }
    }
    //opening -> setScale(windowSize.x/opening -> getLocalBounds().width, windowSize.y/opening -> getLocalBounds().height);//
    
    window -> draw(*spritem);
    window -> draw(*sprite);
    //window -> draw(*opening);//
    /*window -> draw(*spritec);
    window -> draw(*spritee); */ 
}
